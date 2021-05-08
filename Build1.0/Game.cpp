#include "Game.h"
#include "log.h"
const float SCALE = 20.0f;
const float pDx = 5.0f, pDy = 5.0f;
MyGame::MyGame()
{
	cout << "The game is started\n";
}

MyGame::~MyGame()
{
	timer_->Release();
	timer_ = NULL;
	SDL_Quit();
	delete player;
	delete player2;
	block.clear();
	bullets.clear();
	bullets2.clear();
	cout << "The game is closed\n";
}

void MyGame::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("MainWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	mRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	player = new Player(100, 400, 64, 64);
	player2 = new Player(1780, 720, 64, 64);
	block.push_back(new Block(0, 90, 74, 990));
	block.push_back(new Block(1845, 90, 74, 990));
	block.push_back(new Block(0, 90, 1920, 70));
	block.push_back(new Block(0, 1010, 1920, 70));
	block.push_back(new Block(315, 335, 151, 146));
	block.push_back(new Block(174, 771, 151, 146));
	block.push_back(new Block(430, 597, 151, 146));
	block.push_back(new Block(808, 709, 151, 146));
	block.push_back(new Block(1000, 231, 151, 146));
	block.push_back(new Block(1113, 474, 151, 146));
	block.push_back(new Block(1147, 750, 151, 146));
	block.push_back(new Block(1294, 273, 151, 146));
	block.push_back(new Block(1569, 289, 151, 146));
	block.push_back(new Block(689, 363, 151, 146));
	block.push_back(new Block(1411, 561, 151, 146));

	bar.setHP(player->getHP());
	bar.setColor(247, 24, 57, 0, 0, 75);
	bar2.setHP(player2->getHP());
	bar2.setColor(247, 24, 57, 0, 0, 75);
	bull.setTexture(mRender);

	SDL_Surface* test1 = IMG_Load("crosshair.png");
	if (!test1) {
		printf("Unable to load image %s! SDL_image Error: %s\n", "bull.png", IMG_GetError());
	}
	crosshair = SDL_CreateTextureFromSurface(mRender, test1);
	SDL_FreeSurface(test1);

	test1 = IMG_Load("t1.png");
	if (!test1) {
		printf("Unable to load image %s! SDL_image Error: %s\n", "bull.png", IMG_GetError());
	}
	tank1 = SDL_CreateTextureFromSurface(mRender, test1);
	SDL_FreeSurface(test1);

	test1 = IMG_Load("d1.png");
	if (!test1) {
		printf("Unable to load image %s! SDL_image Error: %s\n", "bull.png", IMG_GetError());
	}
	dylo1 = SDL_CreateTextureFromSurface(mRender, test1);
	SDL_FreeSurface(test1);

	test1 = IMG_Load("t2.png");
	if (!test1) {
		printf("Unable to load image %s! SDL_image Error: %s\n", "bull.png", IMG_GetError());
	}
	tank2 = SDL_CreateTextureFromSurface(mRender, test1);
	SDL_FreeSurface(test1);

	test1 = IMG_Load("d2.png");
	if (!test1) {
		printf("Unable to load image %s! SDL_image Error: %s\n", "bull.png", IMG_GetError());
	}
	dylo2 = SDL_CreateTextureFromSurface(mRender, test1);
	SDL_FreeSurface(test1);
	test1 = IMG_Load("fon.png");
	if (!test1) {
		printf("Unable to load image %s! SDL_image Error: %s\n", "bull.png", IMG_GetError());
	}
	pole = SDL_CreateTextureFromSurface(mRender, test1);

	test1 = IMG_Load("menu.png");
	if (!test1) {
		printf("Unable to load image %s! SDL_image Error: %s\n", "bull.png", IMG_GetError());
	}
	menu = SDL_CreateTextureFromSurface(mRender, test1);
	SDL_FreeSurface(test1);

	SDL_ShowWindow(window);
}

void MyGame::Run()
{
	Init();
	timer_ = Timer::Instance();
	handler = EventHandler::Instance();
	while (!isEndless) {
		isEndless = MainMenu();
		if (isEndless) break;
		while (_end)
		{
			Loop();
		}
	}
	return;
}

void MyGame::Loop()
{
	timer_->Update();
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) _end = false;
		handler->Handle(&event);
	}
	if (timer_->DeltaTime() >= 1.0f / FRAME_RATE) {
		CheckControllers();
		Update();
		if (_end)
			Render();
		timer_->Reset();
	}
	return;
}

void MyGame::Update() {
	if (handler->KeyDown(SDLK_ESCAPE) || handler->ButtonDown(cplayer1.getButton(SDL_CONTROLLER_BUTTON_START)) || handler->Button2ndDown(cplayer2.getButton(SDL_CONTROLLER_BUTTON_START))) _end = false;

	if (handler->GetStick2Pos().x > 8000 || handler->GetStick2Pos().x < -8000)
	{
		aim.x = -handler->GetStick2Pos().x;
		aim.y = -handler->GetStick2Pos().y;
		aimnorm = aim / sqrt(aim.x * aim.x + aim.y * aim.y);
	}

	if (handler->GetStick22Pos().x > 8000 || handler->GetStick22Pos().x < -8000) {
		aim2.x = -handler->GetStick22Pos().x;
		aim2.y = -handler->GetStick22Pos().y;
		aimnorm2 = aim2 / sqrt(aim2.x * aim2.x + aim2.y * aim2.y);
	}
	if (handler->GetStick1Pos().x > 8000 || handler->GetStick1Pos().x < -8000) {
		dur.x = -handler->GetStick1Pos().x;
		dur.y = -handler->GetStick1Pos().y;
		durnorm = dur / sqrt(dur.x * dur.x + dur.y * dur.y);
	}
	if (handler->GetStick21Pos().x > 8000 || handler->GetStick21Pos().x < -8000) {
		dur2.x = -handler->GetStick21Pos().x;
		dur2.y = -handler->GetStick21Pos().y;
		durnorm2 = dur2 / sqrt(dur2.x * dur2.x + dur2.y * dur2.y);
	}
	aimrect2.x = player2->getPos().x + 25 - 75 * aimnorm2.x;
	aimrect2.y = player2->getPos().y + 27 - 75 * aimnorm2.y;
	aimrect2.h = 10;
	aimrect2.w = 10;
	aimrect.x = player->getPos().x + 25 - 75 * aimnorm.x;
	aimrect.y = player->getPos().y + 27 - 75 * aimnorm.y;
	aimrect.h = 10;
	aimrect.w = 10;
	ang1 = acos(durnorm.x) * 57.295 * (durnorm.y > 0 ? 1 : -1) - 90;
	ang2 = acos(aimnorm.x) * 57.295 * (aimnorm.y > 0 ? 1 : -1) - 90;
	ang3 = acos(durnorm2.x) * 57.295 * (durnorm2.y > 0 ? 1 : -1) - 90;
	ang4 = acos(aimnorm2.x) * 57.295 * (aimnorm2.y > 0 ? 1 : -1) - 90;

	if (handler->GetStick1Pos().y > 8000)
	{
		player->Move(0, pDy);
		for (auto blocks : block)
			if (check_collision(player->getRect(), blocks->getRect()))
				player->Move(0, -player->getRect().h - (player->getPos().y - blocks->getRect().y));
	}
	if (handler->GetStick1Pos().y < -8000)
	{
		player->Move(0, -pDy);
		for (auto blocks : block)
			if (check_collision(player->getRect(), blocks->getRect()))
				player->Move(0, blocks->getRect().y + blocks->getRect().h - player->getPos().y);
	}
	if (handler->GetStick1Pos().x < -8000)
	{
		player->Move(-pDx, 0);
		for (auto blocks : block)
			if (check_collision(player->getRect(), blocks->getRect()))
				player->Move(blocks->getRect().x + blocks->getRect().w - player->getPos().x, 0);
	}
	if (handler->GetStick1Pos().x > 8000)
	{
		player->Move(pDx, 0);
		for (auto blocks : block)
			if (check_collision(player->getRect(), blocks->getRect()))
				player->Move(-player->getRect().w - (player->getPos().x - blocks->getRect().x), 0);
	}

	if (handler->GetStick21Pos().y > 8000)
	{
		player2->Move(0, pDy);
		for (auto blocks : block)
			if (check_collision(player2->getRect(), blocks->getRect()))
				player2->Move(0, -player2->getRect().h - (player2->getPos().y - blocks->getRect().y));
	}
	if (handler->GetStick21Pos().y < -8000)
	{
		player2->Move(0, -pDy);
		for (auto blocks : block)
			if (check_collision(player2->getRect(), blocks->getRect()))
				player2->Move(0, blocks->getRect().y + blocks->getRect().h - player2->getPos().y);
	}
	if (handler->GetStick21Pos().x < -8000)
	{
		player2->Move(-pDx, 0);
		for (auto blocks : block)
			if (check_collision(player2->getRect(), blocks->getRect()))
				player2->Move(blocks->getRect().x + blocks->getRect().w - player2->getPos().x, 0);
	}
	if (handler->GetStick21Pos().x > 8000)
	{
		player2->Move(pDx, 0);
		for (auto blocks : block)
			if (check_collision(player2->getRect(), blocks->getRect()))
				player2->Move(-player2->getRect().w - (player2->getPos().x - blocks->getRect().x), 0);
	}

	bar.setHP(player->getHP());
	bar2.setHP(player2->getHP());
	if (handler->ButtonDown(cplayer1.getButton(SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)) && d1 > 20) {
		d1 = 0;
		bull.setPos(player->getPos() + 18);
		bull.setVel(aimnorm * -1);
		bullets.push_back(new Bullet(bull));
	}
	if (handler->Button2ndDown(cplayer2.getButton(SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)) && d2 > 20) {
		d2 = 0;
		bull.setPos(player2->getPos() + 18);
		bull.setVel(aimnorm2 * -1);
		bullets2.push_back(new Bullet(bull));
	}

	int s = 0;
	for (size_t t = 0; t < bullets.size(); t++)
		bullets[t]->Move();
	for (auto& blocks : block)
		for (size_t t = 0; t < bullets.size(); t++) {
			s = check_bcollision(blocks->getRect(), SDL_Rect{ bullets[t]->getPos().x,bullets[t]->getPos().y,30,30 });
			if (s)
				bullets[t]->Coll(s);
		}
	for (size_t t = 0; t < bullets.size(); t++)
		if (bullets[t]->getPos().x < 0 || bullets[t]->getPos().x>1920 || bullets[t]->getPos().y < 0 || bullets[t]->getPos().y>1080)
			bullets.erase(bullets.begin() + t);

	for (size_t t = 0; t < bullets2.size(); t++)
		bullets2[t]->Move();
	for (auto& blocks : block)
		for (size_t t = 0; t < bullets2.size(); t++) {
			s = check_bcollision(blocks->getRect(), SDL_Rect{ bullets2[t]->getPos().x,bullets2[t]->getPos().y,30,30 });
			if (s)
				bullets2[t]->Coll(s);
		}

	for (size_t t = 0; t < bullets.size(); t++)
	{
		if (bullets[t]->isDead()) {
			bullets.erase(bullets.begin() + t);
		}
	}
	for (size_t t = 0; t < bullets2.size(); t++) {
		if (bullets2[t]->isDead()) {
			bullets2.erase(bullets2.begin() + t);
		}
	}

	for (size_t t = 0; t < bullets2.size(); t++)
		if (bullets2[t]->getPos().x < 0 || bullets2[t]->getPos().x>1920 || bullets2[t]->getPos().y < 0 || bullets2[t]->getPos().y>1080)
			bullets2.erase(bullets2.begin() + t);
	for (size_t t = 0; t < bullets.size(); t++) {
		if (check_collision(player2->getRect(), bullets[t]->getRect())) {
			bullets.erase(bullets.begin() + t);
			player2->Damage();
		}
	}
	for (size_t t = 0; t < bullets2.size(); t++) {
		if (check_collision(player->getRect(), bullets2[t]->getRect())) {
			bullets2.erase(bullets2.begin() + t);
			player->Damage();
		}
	}

	d1++;
	d2++;

	if (player->isDead()) {
		EndGame(1); _end = false; 		player->setHP(1000);
		player2->setHP(1000);
		player->setPos(100, 400);
		player2->setPos(1845, 720);
	}
	if (player2->isDead()) {
		EndGame(2); _end = false; 		player->setHP(1000);
		player2->setHP(1000);
		player->setPos(100, 400);
		player2->setPos(1845, 720);
	}
}

void MyGame::Render() {
	SDL_SetRenderDrawColor(mRender, 0, 0, 0, 0);
	SDL_RenderClear(mRender);
	SDL_RenderCopy(mRender, pole, 0, 0);
	SDL_SetRenderDrawColor(mRender, 255, 0, 0, 0);

	SDL_RenderCopyEx(mRender, tank1, 0, &player->getRect(), ang1, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(mRender, dylo1, 0, &player->getRect(), ang2, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(mRender, tank2, 0, &player2->getRect(), ang3, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(mRender, dylo2, 0, &player2->getRect(), ang4, NULL, SDL_FLIP_NONE);

	SDL_SetRenderDrawColor(mRender, 0, 0, 255, 0);

	SDL_RenderDrawRect(mRender, &aimrect);
	SDL_RenderDrawRect(mRender, &aimrect2);
	SDL_RenderCopy(mRender, crosshair, 0, &aimrect);
	SDL_RenderCopy(mRender, crosshair, 0, &aimrect2);
	SDL_SetRenderDrawColor(mRender, 255, 0, 0, 0);
	for (size_t t = 0; t < bullets.size(); t++)
		bullets[t]->Draw(mRender);
	SDL_SetRenderDrawColor(mRender, 255, 255, 255, 0);
	for (size_t t = 0; t < bullets2.size(); t++)
		bullets2[t]->Draw(mRender);

	bar.Draw(mRender);
	bar2.Draw(mRender);

	SDL_RenderPresent(mRender);
}

void MyGame::CheckControllers()
{
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	gGameController = SDL_JoystickOpen(0);
	controller = SDL_GameControllerOpen(0);
	if (controller) cplayer1.Init(controller);
	gGameController1 = SDL_JoystickOpen(1);
	controller1 = SDL_GameControllerOpen(1);
	if (controller1) cplayer2.Init(controller1);
	handler->setMapping();
}

bool MyGame::MainMenu()
{
	bool isExit = false;
	SDL_RenderCopy(mRender, menu, 0, 0);
	SDL_RenderPresent(mRender);

	while (!isExit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) _end = false;
			handler->Handle(&event);
		}
		CheckControllers();

		if (handler->ButtonDown(cplayer1.getButton(SDL_CONTROLLER_BUTTON_A))) return false;
		if (handler->Button2ndDown(cplayer2.getButton(SDL_CONTROLLER_BUTTON_A))) return false;
		if (handler->ButtonDown(cplayer1.getButton(SDL_CONTROLLER_BUTTON_X))) return false;
		if (handler->Button2ndDown(cplayer2.getButton(SDL_CONTROLLER_BUTTON_X))) return false;
		if (handler->ButtonDown(cplayer1.getButton(SDL_CONTROLLER_BUTTON_START))) return true;
		if (handler->Button2ndDown(cplayer2.getButton(SDL_CONTROLLER_BUTTON_START))) return true;
	}
	return false;
}

void MyGame::EndGame(int a)
{
	ostringstream os;
	os << "playerwon" << a << ".jpg";
	SDL_Surface* test1 = IMG_Load(os.str().c_str());
	os.str("");
	if (!test1) {
		printf("Unable to load image %s! SDL_image Error: %s\n", "bull.png", IMG_GetError());
	}
	endGame = SDL_CreateTextureFromSurface(mRender, test1);
	SDL_RenderCopy(mRender, endGame, 0, 0);
	SDL_RenderPresent(mRender);
	SDL_Delay(5000);
}