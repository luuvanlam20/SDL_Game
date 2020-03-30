#include"TankObject.h";
MainObject::MainObject()
{
	frame_ = 0;
	x_pos_ = 100;
	y_pos_ = 300;
	x_val_ = 0;
	y_val_ = 0;
	width_frame_ = 0;
	height_frame_ = 0;
	status_ = -1;
	input_type_.left_ = 0;
	input_type_.right_ = 0;
	input_type_.up_ = 0;
	input_type_.down_ = 0;
	on_ground_ = false;
}

MainObject::~MainObject()
{
	
}

bool MainObject::LoadImage(std::string path, SDL_Renderer* screen)
{
	bool ret = BaseObject::LoadImage(path, screen);
	return ret;
}

void MainObject::Set_clipsLR()
{
	width_frame_ = rect_.w / 8;
	height_frame_ = rect_.h;
	if (width_frame_ > 0 && height_frame_ > 0)
	{
		frame_clip_[0].x = 0;
		frame_clip_[0].y = 0;
		frame_clip_[0].w = width_frame_;
		frame_clip_[0].h = height_frame_-10;

		frame_clip_[1].x = width_frame_;
		frame_clip_[1].y = 0;
		frame_clip_[1].w = width_frame_;
		frame_clip_[1].h = height_frame_-10;

		frame_clip_[2].x = 2* width_frame_;
		frame_clip_[2].y = 0;
		frame_clip_[2].w = width_frame_;
		frame_clip_[2].h = height_frame_-10;

		frame_clip_[3].x = 3 * width_frame_;
		frame_clip_[3].y = 0;
		frame_clip_[3].w = width_frame_;
		frame_clip_[3].h = height_frame_-10;

		frame_clip_[4].x = 4 * width_frame_;
		frame_clip_[4].y = 0;
		frame_clip_[4].w = width_frame_;
		frame_clip_[4].h = height_frame_-10;

		frame_clip_[5].x = 5 * width_frame_;
		frame_clip_[5].y = 0;
		frame_clip_[5].w = width_frame_;
		frame_clip_[5].h = height_frame_-10;

		frame_clip_[6].x = 6 * width_frame_;
		frame_clip_[6].y = 0;
		frame_clip_[6].w = width_frame_;
		frame_clip_[6].h = height_frame_-10;

		frame_clip_[7].x = 7 * width_frame_;
		frame_clip_[7].y = 0;
		frame_clip_[7].w = width_frame_;
		frame_clip_[7].h = height_frame_ -10;
	}
}
void MainObject::Set_clipsDU()
{
	width_frame_ = rect_.w;
	height_frame_ = rect_.h / 8;
	if (width_frame_ > 0 && height_frame_ > 0)
	{
		frame_clip_[0].x = 0;
		frame_clip_[0].y = 0;
		frame_clip_[0].w = width_frame_ - 10;
		frame_clip_[0].h = height_frame_;

		frame_clip_[1].x = 0;
		frame_clip_[1].y = height_frame_;
		frame_clip_[1].w = width_frame_ - 10;
		frame_clip_[1].h = height_frame_;

		frame_clip_[2].x = 0;
		frame_clip_[2].y = 2*height_frame_;
		frame_clip_[2].w = width_frame_ - 10;
		frame_clip_[2].h = height_frame_;

		frame_clip_[3].x = 0;
		frame_clip_[3].y = 3* height_frame_;
		frame_clip_[3].w = width_frame_ - 10;
		frame_clip_[3].h = height_frame_;

		frame_clip_[4].x = 0;
		frame_clip_[4].y = 4* height_frame_;
		frame_clip_[4].w = width_frame_ - 10;
		frame_clip_[4].h = height_frame_;

		frame_clip_[5].x = 0;
		frame_clip_[5].y = 5 * height_frame_;
		frame_clip_[5].w = width_frame_ - 10;
		frame_clip_[5].h = height_frame_;

		frame_clip_[6].x = 0;
		frame_clip_[6].y = 6 * height_frame_;
		frame_clip_[6].w = width_frame_ - 10;
		frame_clip_[6].h = height_frame_;

		frame_clip_[7].x = 0;
		frame_clip_[7].y = 7 * height_frame_;
		frame_clip_[7].w = width_frame_ - 10;
		frame_clip_[7].h = height_frame_;
	}
}

void MainObject::Show(SDL_Renderer* des)
{
	if (status_ == MOVE_LEFT)
	{
		LoadImage("tankleft.png", des);
	}
	else
		if(status_ == MOVE_RIGHT)
	{
		LoadImage("tankright.png", des);
	}
		else if (status_ == MOVE_UP)
		{
			LoadImage("tankup.png", des);
		}
		else if (status_ = MOVE_DOWN)
		{
	
			LoadImage("tankdown.png", des);
		}
		
	if (input_type_.left_ == 1 || input_type_.right_ == 1 || input_type_.up_ == 1 || input_type_.down_ == 1)
	{
		frame_++;
	}
	else {
		frame_ = 0;
	}

	if (frame_ >= 8) frame_ = 0;

	rect_.x = x_pos_;
	rect_.y = y_pos_;

	SDL_Rect* current_clip = &frame_clip_[frame_];
	SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };

	SDL_RenderCopy(des, p_object_, current_clip, &renderQuad );
}

void MainObject::HandelInput(SDL_Event events, SDL_Renderer* screen)
{
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_RIGHT:
		{
			status_ = MOVE_RIGHT;
			input_type_.right_ = 1;
			input_type_.left_ = 0;
		}
		break;
		case SDLK_LEFT:
		{
			status_ = MOVE_LEFT;
			input_type_.left_ = 1;
			input_type_.right_ = 0;
		}
		break;
		case SDLK_UP:
		{
			status_ = MOVE_UP;
			input_type_.up_ = 1;
			input_type_.down_ = 0;
		}
		break;
		case SDLK_DOWN:
		{
			status_ = MOVE_DOWN;
			input_type_.down_ = 1;
			input_type_.up_ = 0;
		}
		break;
		}
	} 
	else if (events.type == SDL_KEYUP)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_RIGHT:
		{
			status_ = MOVE_RIGHT;
			input_type_.right_ = 0;
		}
		break;
		case SDLK_LEFT:
		{
			status_ = MOVE_LEFT;
			input_type_.left_ = 0;
		}
		break;
		case SDLK_UP:
		{
			status_ = MOVE_UP;
			input_type_.up_ = 0;
			input_type_.down_ = 0;
		}
		break;
		case SDLK_DOWN:
		{
			status_ = MOVE_DOWN;
			input_type_.down_ = 0;
			input_type_.up_ = 0;
		}
		break;
		}
	}
}

void MainObject::DoTank(Map& map_data)
{
	x_val_ = 0;
	y_val_ =0;

	

	if (input_type_.left_ == 1)
	{
		x_val_ -= TANK_SPEED; 
	}
	else if (input_type_.right_ == 1)
	{
		x_val_ += TANK_SPEED;
	}
	else if (input_type_.up_ == 1)
	{
		y_val_ -= TANK_SPEED;
	}
	else if (input_type_.down_ == 1)
	{
		y_val_ += TANK_SPEED;
	}

	CheckToMap(map_data);
}

void MainObject::CheckToMap(Map& map_data)
{
	int x1 = 0;
	int x2 = 0;

	int y1 = 0;
	int y2 = 0;

	//check theo chieu ngang
	int height_min = height_frame_ < TILE_SIZE ? height_frame_ : TILE_SIZE;
	
	x1 = (x_pos_ + x_val_) / TILE_SIZE;
	x2 = (x_pos_ + x_val_ + width_frame_ - 1) / TILE_SIZE;

	y1 = y_pos_ / TILE_SIZE;
	y2 = (y_pos_ + height_min - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < (MAX_MAP_X) && y1 >= 0 && y2 < MAX_MAP_Y)
	{
		if (x_val_ > 0)
		{
			if (map_data.tile[y1][x2] == 1 || map_data.tile[y2][x2] == 1 )
			{
				x_pos_ = x2 * TILE_SIZE;
				x_pos_ -= (width_frame_ + 1);
				x_val_ = 0;
			}
		}
		else if (x_val_ < 0)
		{
			if (map_data.tile[y1][x1] == 1 || map_data.tile[y2][x1] == 1)
			{
				x_pos_ = (x1 + 1)* TILE_SIZE;
				x_val_ = 0;
				 
			}
		}
	}
	//check theo chieu doc

	int width_min = width_frame_ < TILE_SIZE ? width_frame_ : TILE_SIZE;
	x1 = (x_pos_) / TILE_SIZE;
	x2 = (x_pos_ + width_min) / TILE_SIZE;
	y1 = (y_pos_ + y_val_) / TILE_SIZE;
	y2 = (y_pos_ + y_val_ + height_frame_ - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
	{
		if (y_val_ > 0)
		{
			if (map_data.tile[y2][x1] == 1 || map_data.tile[y2][x2] == 1)
			{
				y_pos_ = y2 * TILE_SIZE;
				y_pos_ -= (height_frame_ + 1);
				y_val_ = 0;
				on_ground_ = true;
			}
		}
		else if (y_val_ < 0)
		{
			if (map_data.tile[y1][x1] == 1 || map_data.tile[y1][x2] == 1)
			{
				y_pos_ = (y1 + 1)*TILE_SIZE;
				y_val_ = 0;
			}
		}
	}

	x_pos_ += x_val_;
	y_pos_ += y_val_;

	if (x_pos_ < 0 || x_pos_ + width_frame_ > SCREEN_WIDTH)
	{
		x_pos_ -= x_val_;
	}
	if (y_pos_ < 0 || y_pos_ + 64 > SCREEN_HEIGHT)
	{
		y_pos_ -= y_val_;
	}
	
}

