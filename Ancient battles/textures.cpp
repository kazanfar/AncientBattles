#include "textures.h"

Textures::Textures()
{
	texName_countries = new GLuint[num_text_countries];
	taux_countries = new AUX_RGBImageRec*[num_text_countries];

	texName_1 = new GLuint[num_text_warriors_1];
	taux_1 = new AUX_RGBImageRec*[num_text_warriors_1];

	texName_2 = new GLuint[num_text_warriors_2];
	taux_2 = new AUX_RGBImageRec*[num_text_warriors_2];

	texName_3 = new GLuint[num_text_warriors_3];
	taux_3 = new AUX_RGBImageRec*[num_text_warriors_3];

	texName_4 = new GLuint[num_text_warriors_4];
	taux_4 = new AUX_RGBImageRec*[num_text_warriors_4];

	texName_5 = new GLuint[num_text_warriors_5];
	taux_5 = new AUX_RGBImageRec*[num_text_warriors_5];

	texName_6 = new GLuint[num_text_warriors_6];
	taux_6 = new AUX_RGBImageRec*[num_text_warriors_6];

	Textures::loading_textures();
}

void Textures::loading_textures()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);

	glGenTextures(num_text_countries, texName_countries);
	glGenTextures(num_text_warriors_1, texName_1);
	glGenTextures(num_text_warriors_2, texName_2);
	glGenTextures(num_text_warriors_3, texName_3);
	glGenTextures(num_text_warriors_4, texName_4);
	glGenTextures(num_text_warriors_5, texName_5);
	glGenTextures(num_text_warriors_6, texName_6);
	
	//countries
	taux_countries[0] = auxDIBImageLoadA("../img_country_warriors/Barbarians/barbarians_state.bmp");
	taux_countries[1] = auxDIBImageLoadA("../img_country_warriors/Carthage/carthage_state.bmp");
	taux_countries[2] = auxDIBImageLoadA("../img_country_warriors/Egypt/egypt_state.bmp");
	taux_countries[3] = auxDIBImageLoadA("../img_country_warriors/Parthia/parthia_state.bmp");
	taux_countries[4] = auxDIBImageLoadA("../img_country_warriors/Rome/rome_state.bmp");
	taux_countries[5] = auxDIBImageLoadA("../img_country_warriors/Seleucids/seleucids_state.bmp");

	for (int i = 0; i < num_text_countries; ++i)
	{
		glBindTexture(GL_TEXTURE_2D, texName_countries[i]);
		gluBuild2DMipmaps(GL_TEXTURE_2D,3,taux_countries[i]->sizeX, taux_countries[i]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, taux_countries[i]->data);
	}
		
	//Barbarians
	taux_1[0] = auxDIBImageLoadA("../img_country_warriors/Barbarians/barbarians_horseman.bmp");
	taux_1[1] = auxDIBImageLoadA("../img_country_warriors/Barbarians/barbarians_lancer.bmp");
		
	for (int i = 0; i < num_text_warriors_1; ++i)
	{
		glBindTexture(GL_TEXTURE_2D, texName_1[i]);
		gluBuild2DMipmaps(GL_TEXTURE_2D,3,taux_1[i]->sizeX, taux_1[i]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, taux_1[i]->data);
	}

	//Carthage
	taux_2[0] = auxDIBImageLoadA("../img_country_warriors/Carthage/carthage_cavalry.bmp");
	taux_2[1] = auxDIBImageLoadA("../img_country_warriors/Carthage/carthage_elephants.bmp");
	taux_2[2] = auxDIBImageLoadA("../img_country_warriors/Carthage/carthage_infantry.bmp");


	for (int i = 0; i < num_text_warriors_2; ++i)
	{
		glBindTexture(GL_TEXTURE_2D, texName_2[i]);
		gluBuild2DMipmaps(GL_TEXTURE_2D,3,taux_2[i]->sizeX, taux_2[i]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, taux_2[i]->data);
	}

	//Egypt
	taux_3[0] = auxDIBImageLoadA("../img_country_warriors/Egypt/egypt_cavalry.bmp");
	taux_3[1] = auxDIBImageLoadA("../img_country_warriors/Egypt/egypt_infantry.bmp");
		
	for (int i = 0; i < num_text_warriors_3; ++i)
	{
		glBindTexture(GL_TEXTURE_2D, texName_3[i]);
		gluBuild2DMipmaps(GL_TEXTURE_2D,3,taux_3[i]->sizeX, taux_3[i]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, taux_3[i]->data);
	}

	//Parthia
	taux_4[0] = auxDIBImageLoadA("../img_country_warriors/Parthia/parthia_heavycavalry.bmp");
	taux_4[1] = auxDIBImageLoadA("../img_country_warriors/Parthia/parthia_lightcavalry.bmp");
		
	for (int i = 0; i < num_text_warriors_4; ++i)
	{
		glBindTexture(GL_TEXTURE_2D, texName_4[i]);
		gluBuild2DMipmaps(GL_TEXTURE_2D,3,taux_4[i]->sizeX, taux_4[i]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, taux_4[i]->data);
	}

	//Rome
	taux_5[0] = auxDIBImageLoadA("../img_country_warriors/Rome/rome_arta.bmp");
	taux_5[1] = auxDIBImageLoadA("../img_country_warriors/Rome/rome_horseman.bmp");
	taux_5[2] = auxDIBImageLoadA("../img_country_warriors/Rome/rome_archer.bmp");
	taux_5[3] = auxDIBImageLoadA("../img_country_warriors/Rome/rome_legioner.bmp");
		
	for (int i = 0; i < num_text_warriors_5; ++i)
	{
		glBindTexture(GL_TEXTURE_2D, texName_5[i]);
		gluBuild2DMipmaps(GL_TEXTURE_2D,3,taux_5[i]->sizeX, taux_5[i]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, taux_5[i]->data);
	}

	//Seleucids
	taux_6[0] = auxDIBImageLoadA("../img_country_warriors/Seleucids/seleucids_arta.bmp");
	taux_6[1] = auxDIBImageLoadA("../img_country_warriors/Seleucids/seleucids_cavalry.bmp");
	taux_6[2] = auxDIBImageLoadA("../img_country_warriors/Seleucids/seleucids_elephants.bmp");
	taux_6[3] = auxDIBImageLoadA("../img_country_warriors/Seleucids/seleucids_infantry.bmp");
		
	for (int i = 0; i < num_text_warriors_6; ++i)
	{
		glBindTexture(GL_TEXTURE_2D, texName_6[i]);
		gluBuild2DMipmaps(GL_TEXTURE_2D,3,taux_6[i]->sizeX, taux_6[i]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, taux_6[i]->data);
	}

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

Textures::~Textures()
{
	delete[] texName_countries;
	delete[] texName_1;
	delete[] texName_2;
	delete[] texName_3;
	delete[] texName_4;
	delete[] texName_5;
	delete[] texName_6;

	delete[] taux_countries;
	delete[] taux_1;
	delete[] taux_2;
	delete[] taux_3;
	delete[] taux_4;
	delete[] taux_5;
	delete[] taux_6;
}

void Fonts::print_bitmap_string(void* font, char* s) const
{
	if (s && strlen(s)) {
		while (*s) {
			glutBitmapCharacter(font, *s);
			s++;
		}
	}
}

void Fonts::print_stroke_string(void* font, char* s) const
{
	if (s && strlen(s)) {
		while (*s) {
			glutStrokeCharacter(font, *s);
			s++;
		}
	}
}

char* Fonts::string_to_ptrchar(string str) const
{
	char *cstr = new char[str.length() + 1];
	strcpy(cstr, str.c_str());
	return cstr;
}

Countries::Countries ()
{
	enum_countries = NONE;
	
	pair<string, string> barbarians_barbarians("barbarians", "barbarians");
	pair<string, string> barbarians_carthage("barbarians", "carthage");
	pair<string, string> barbarians_egypt("barbarians", "egypt");
	pair<string, string> barbarians_parthia("barbarians", "parthia");
	pair<string, string> barbarians_rome("barbarians", "rome");
	pair<string, string> barbarians_seleucids("barbarians", "seleucids");

	pair<string, string> carthage_barbarians("carthage", "barbarians");
	pair<string, string> carthage_carthage("carthage", "carthage");
	pair<string, string> carthage_egypt("carthage", "egypt");
	pair<string, string> carthage_parthia("carthage", "parthia");
	pair<string, string> carthage_rome("carthage", "rome");
	pair<string, string> carthage_seleucids("carthage", "seleucids");

	pair<string, string> egypt_barbarians("egypt", "barbarians");
	pair<string, string> egypt_carthage("egypt", "carthage");
	pair<string, string> egypt_egypt("egypt", "egypt");
	pair<string, string> egypt_parthia("egypt", "parthia");
	pair<string, string> egypt_rome("egypt", "rome");
	pair<string, string> egypt_seleucids("egypt", "seleucids");

	pair<string, string> parthia_barbarians("parthia", "barbarians");
	pair<string, string> parthia_carthage("parthia", "carthage");
	pair<string, string> parthia_egypt("parthia", "egypt");
	pair<string, string> parthia_parthia("parthia", "parthia");
	pair<string, string> parthia_rome("parthia", "rome");
	pair<string, string> parthia_seleucids("parthia", "seleucids");

	pair<string, string> rome_barbarians("rome", "barbarians");
	pair<string, string> rome_carthage("rome", "carthage");
	pair<string, string> rome_egypt("rome", "egypt");
	pair<string, string> rome_parthia("rome", "parthia");
	pair<string, string> rome_rome("rome", "rome");
	pair<string, string> rome_seleucids("rome", "seleucids");

	pair<string, string> seleucids_barbarians("seleucids", "barbarians");
	pair<string, string> seleucids_carthage("seleucids", "carthage");
	pair<string, string> seleucids_egypt("seleucids", "egypt");
	pair<string, string> seleucids_parthia("seleucids", "parthia");
	pair<string, string> seleucids_rome("seleucids", "rome");
	pair<string, string> seleucids_seleucids("seleucids", "seleucids");

	country_effects[barbarians_barbarians] = 1.0;
	country_effects[barbarians_carthage] = 0.95;
	country_effects[barbarians_egypt] = 1.0;
	country_effects[barbarians_parthia] = 0.95;
	country_effects[barbarians_rome] = 1.0;
	country_effects[barbarians_seleucids] = 1.05;

	country_effects[carthage_barbarians] = 1.0/country_effects[barbarians_carthage];//20/19
	country_effects[carthage_carthage] = 1.0;
	country_effects[carthage_egypt] = 1.0;
	country_effects[carthage_parthia] = 1.0;
	country_effects[carthage_rome] = 0.88;
	country_effects[carthage_seleucids] = 1.0;

	country_effects[egypt_barbarians] = 1.0/country_effects[barbarians_egypt];//1.0
	country_effects[egypt_carthage] = 1.0/country_effects[carthage_egypt];//1.0
	country_effects[egypt_egypt] = 1.0;
	country_effects[egypt_parthia] = 1.0;
	country_effects[egypt_rome] = 0.8;
	country_effects[egypt_seleucids] = 0.95;
	
	country_effects[parthia_barbarians] = 1.0/country_effects[barbarians_parthia];//20/19
	country_effects[parthia_carthage] = 1.0/country_effects[carthage_parthia];//1.0
	country_effects[parthia_egypt] = 1.0/country_effects[egypt_parthia];//1.0
	country_effects[parthia_parthia] = 1.0;
	country_effects[parthia_rome] = 1.05;
	country_effects[parthia_seleucids] = 1.1;

	country_effects[rome_barbarians] = 1.0/country_effects[barbarians_rome];//1.0
	country_effects[rome_carthage] = 1.0/country_effects[carthage_rome];//25/22
	country_effects[rome_egypt] = 1.0/country_effects[egypt_rome];//1.25
	country_effects[rome_parthia] = 1.0/country_effects[parthia_rome];//20/21
	country_effects[rome_rome] = 1.0;
	country_effects[rome_seleucids] = 1.05;

	country_effects[seleucids_barbarians] = 1.0/country_effects[barbarians_seleucids];//20/21
	country_effects[seleucids_carthage] = 1.0/country_effects[carthage_seleucids];//1.0
	country_effects[seleucids_egypt] = 1.0/country_effects[egypt_seleucids];//20/19
	country_effects[seleucids_parthia] = 1.0/country_effects[parthia_seleucids];//10/11
	country_effects[seleucids_rome] = 1.0/country_effects[rome_seleucids];//20/21
	country_effects[seleucids_seleucids] = 1.0;
}

void Countries::switch_off_flags() const
{
	choose_barbarians = choose_carthage = choose_egypt = choose_parthia = choose_rome = choose_seleucids = false;
}

void Countries::set_your_score(int score)
{
	your_score = score;
}

int Countries::get_your_score()
{
	return your_score;
}

void Countries::set_enemy_score(int score)
{
	enemy_score = score;
}

int Countries::get_enemy_score()
{
	return enemy_score;
}

bool Picture_Countries::is_Barbarians (int x, int y) const
{
	return x >= 0 && x < width/3 && y >= 0 && y < (height - 100)/2;
}

bool Picture_Countries::is_Carthage (int x, int y) const
{
	return x >= width/3 && x < 2*width/3 && y >= 0 && y < (height - 100)/2;
}

bool Picture_Countries::is_Egypt (int x, int y) const
{
	return x >= 2*width/3 && x < width && y >= 0 && y < (height - 100)/2;
}

bool Picture_Countries::is_Parthia (int x, int y) const
{
	return x >= 0 && x < width/3 && y >= 290 && y < height - 100;
}

bool Picture_Countries::is_Rome (int x, int y) const
{
	return x >= width/3 && x < 2*width/3 && y >= 290 && y < height - 100;
}

bool Picture_Countries::is_Seleucids (int x, int y) const
{
	return x >= 2*width/3 && x < width && y >= 290 && y < height - 100;
}

Warriors::Warriors() : _money(0)
{
	inf_cost = 500;//18  28
	heavycav_cost = 1000;//24 41
	lightcav_cost = 1200;//28 42
	arch_cost = 400;//17 24
	arta_cost = 900;//20 45
	eleph_cost = 1500;//28 54
	//18
	parameters["infantry"] = 18.0;
	//20
	parameters["artillery"] = 20.0;
	//28
	parameters["elephants"] = 28.0;
	//24
	parameters["heavyhorseman"] = 24.0;
	//28
	parameters["lighthorseman"] = 28.0;
	//17
	parameters["archers"] = 17.0;

	pair<string, string> inf_inf("infantry", "infantry");
	pair<string, string> inf_arch("infantry", "archers");
	pair<string, string> inf_heavycav("infantry", "heavyhorseman");
	pair<string, string> inf_lightcav("infantry", "lighthorseman");
	pair<string, string> inf_eleph("infantry", "elephants");
	pair<string, string> inf_arta("infantry", "artillery");

	pair<string, string> arch_inf("archers", "infantry");
	pair<string, string> arch_arch("archers", "archers");
	pair<string, string> arch_heavycav("archers", "heavyhorseman");
	pair<string, string> arch_lightcav("archers", "lighthorseman");
	pair<string, string> arch_eleph("archers", "elephants");
	pair<string, string> arch_arta("archers", "artillery");

	pair<string, string> heavycav_inf("heavyhorseman", "infantry");
	pair<string, string> heavycav_arch("heavyhorseman", "archers");
	pair<string, string> heavycav_heavycav("heavyhorseman", "heavyhorseman");
	pair<string, string> heavycav_lightcav("heavyhorseman", "lighthorseman");
	pair<string, string> heavycav_eleph("heavyhorseman", "elephants");
	pair<string, string> heavycav_arta("heavyhorseman", "artillery");

	pair<string, string> lightcav_inf("lighthorseman", "infantry");
	pair<string, string> lightcav_arch("lighthorseman", "archers");
	pair<string, string> lightcav_heavycav("lighthorseman", "heavyhorseman");
	pair<string, string> lightcav_lightcav("lighthorseman", "lighthorseman");
	pair<string, string> lightcav_eleph("lighthorseman", "elephants");
	pair<string, string> lightcav_arta("lighthorseman", "artillery");

	pair<string, string> eleph_inf("elephants", "infantry");
	pair<string, string> eleph_arch("elephants", "archers");
	pair<string, string> eleph_heavycav("elephants", "heavyhorseman");
	pair<string, string> eleph_lightcav("elephants", "lighthorseman");
	pair<string, string> eleph_eleph("elephants", "elephants");
	pair<string, string> eleph_arta("elephants", "artillery");

	pair<string, string> arta_inf("artillery", "infantry");
	pair<string, string> arta_arch("artillery", "archers");
	pair<string, string> arta_heavycav("artillery", "heavyhorseman");
	pair<string, string> arta_lightcav("artillery", "lighthorseman");
	pair<string, string> arta_eleph("artillery", "elephants");
	pair<string, string> arta_arta("artillery", "artillery");

	warrior_effects[inf_inf] = 1.0;
	warrior_effects[inf_arch] = 1.2;
	warrior_effects[inf_heavycav] = 0.75;
	warrior_effects[inf_lightcav] = 0.75;
	warrior_effects[inf_eleph] = 0.7;
	warrior_effects[inf_arta] = 0.75;

	warrior_effects[arch_inf] = 1.0/warrior_effects[inf_arch];//5/6
	warrior_effects[arch_arch] = 1.0;
	warrior_effects[arch_heavycav] = 0.7;
	warrior_effects[arch_lightcav] = 0.7;
	warrior_effects[arch_eleph] = 0.6;
	warrior_effects[arch_arta] = 0.69;

	warrior_effects[heavycav_inf] = 1.0/warrior_effects[inf_heavycav];//4/3
	warrior_effects[heavycav_arch] = 1.0/warrior_effects[arch_heavycav];//10/7
	warrior_effects[heavycav_heavycav] = 1.0;
	warrior_effects[heavycav_lightcav] = 1.05;
	warrior_effects[heavycav_eleph] = 0.8;
	warrior_effects[heavycav_arta] = 0.9;
	
	warrior_effects[lightcav_inf] = 1.0/warrior_effects[inf_lightcav];//4/3
	warrior_effects[lightcav_arch] = 1.0/warrior_effects[arch_lightcav];//10/7
	warrior_effects[lightcav_heavycav] = 1.0/warrior_effects[heavycav_lightcav];//20/21
	warrior_effects[lightcav_lightcav] = 1.0;
	warrior_effects[lightcav_eleph] = 0.7;
	warrior_effects[lightcav_arta] = 0.95;

	warrior_effects[eleph_inf] = 1.0/warrior_effects[inf_eleph];//10/7
	warrior_effects[eleph_arch] = 1.0/warrior_effects[arch_eleph];//5/3
	warrior_effects[eleph_heavycav] = 1.0/warrior_effects[heavycav_eleph];//1.25
	warrior_effects[eleph_lightcav] = 1.0/warrior_effects[lightcav_eleph];//10/7
	warrior_effects[eleph_eleph] = 1.0;
	warrior_effects[eleph_arta] = 1.2;

	warrior_effects[arta_inf] = 1.0/warrior_effects[inf_arta];//4/3
	warrior_effects[arta_arch] = 1.0/warrior_effects[arch_arta];//100/69
	warrior_effects[arta_heavycav] = 1.0/warrior_effects[heavycav_arta];//10/9
	warrior_effects[arta_lightcav] = 1.0/warrior_effects[lightcav_arta];//10/7
	warrior_effects[arta_eleph] = 1.0/warrior_effects[eleph_arta];//5/6
	warrior_effects[arta_arta] = 1.0;

	troops["infantry"] = 0;
	troops["artillery"] = 0;
	troops["elephants"] = 0;
	troops["heavyhorseman"] = 0;
	troops["lighthorseman"] = 0;
	troops["archers"] = 0;

	money = "";
}

int Warriors::get_inf_cost() const
{
	return inf_cost;
}

int Warriors::get_heavycav_cost() const
{
	return heavycav_cost;
}

int Warriors::get_lightcav_cost() const
{
	return lightcav_cost;
}
	
int Warriors::get_arta_cost() const
{
	return arta_cost;
}

int Warriors::get_eleph_cost() const
{
	return eleph_cost;
}

int Warriors::get_arch_cost() const
{
	return arch_cost;
}

void Warriors::set_money(int money)
{
	_money = money;
}

int Warriors::get_money() const
{
	return _money;
}

Picture_Warriors::Picture_Warriors() : first_case(250), second_case(250), third_case(300)
{
}

int Picture_Warriors::get_first_case() const
{
	return first_case;
}

int Picture_Warriors::get_second_case() const
{
	return second_case;
}

int Picture_Warriors::get_third_case() const
{
	return third_case;
}

bool Picture_Warriors::is_first_in_two(int x, int y) const
{
	return x >= 0 && x < width/2 && y >= 0 && y < height - first_case;
}

bool Picture_Warriors::is_second_in_two(int x, int y) const
{
	return x >= width/2 && x < width && y >= 0 && y < height - first_case;
}

bool Picture_Warriors::is_first_in_three(int x, int y) const
{
	return x >= 0 && x < width/3 && y >= 0 && y < height - second_case;
}

bool Picture_Warriors::is_second_in_three(int x, int y) const
{
	return x >= width/3 && x < 2*width/3 && y >= 0 && y < height - second_case;
}

bool Picture_Warriors::is_third_in_three(int x, int y) const
{
	return x >= 2*width/3 && x < width && y >= 0 && y < height - second_case;
}

bool Picture_Warriors::is_first_in_four(int x, int y) const
{
	return x >= 0 && x < width/4 && y >= 0 && y < height - third_case;
}
	
bool Picture_Warriors::is_second_in_four(int x, int y) const
{
	return x >= width/4 && x < width/2 && y >= 0 && y < height - third_case;
}

bool Picture_Warriors::is_third_in_four(int x, int y) const
{
	return x >= width/2 && x < 3*width/4 && y >= 0 && y < height - third_case;
}

bool Picture_Warriors::is_forth_in_four(int x, int y) const
{
	return x >= 3*width/4 && x < width && y >= 0 && y < height - third_case;
}

State::State()
{
	pair<string, int> p("intro none", 0);
	states.push_back(p);
}

void Algorithms_EnemyCountry::alg_1(int enemy_country_num)
{
	enemy_troops["infantry"] = 0;
	enemy_troops["artillery"] = 0;
	enemy_troops["elephants"] = 0;
	enemy_troops["heavyhorseman"] = 0;
	enemy_troops["lighthorseman"] = 0;
	enemy_troops["archers"] = 0;
	int enemy_money = get_money();
	int money_heavycav, money_lightcav, money_inf, money_arch, money_arta, money_eleph;
	int rest;
	switch(enemy_country_num)
	{
		case 31 :
		case 33:
			{
				money_heavycav = money_inf = enemy_money/2;
				enemy_troops["heavyhorseman"] += money_heavycav/get_heavycav_cost();
				enemy_troops["infantry"] += money_inf/get_inf_cost();
				rest = (money_heavycav % get_heavycav_cost()) + (money_inf % get_inf_cost());
				enemy_troops["infantry"] += rest/get_inf_cost();
				break;
			};
		case 32:
			{
				money_heavycav = money_eleph = money_inf = enemy_money/3;
				enemy_troops["heavyhorseman"] += money_heavycav/get_heavycav_cost();
				enemy_troops["elephants"] += money_eleph/get_eleph_cost();
				enemy_troops["infantry"] += money_inf/get_inf_cost();
				rest = (money_heavycav % get_heavycav_cost()) + (money_inf % get_inf_cost()) + (money_eleph % get_eleph_cost());
				enemy_troops["infantry"] += rest/get_inf_cost();
				break;
			};
		case 34:
			{
				money_heavycav = money_lightcav = enemy_money/2;
				enemy_troops["heavyhorseman"] += money_heavycav/get_heavycav_cost();
				enemy_troops["lighthorseman"] += money_lightcav/get_lightcav_cost();
				rest = (money_heavycav % get_heavycav_cost()) + (money_lightcav % get_lightcav_cost());
				enemy_troops["heavyhorseman"] += rest/get_heavycav_cost();
				break;
			};
		case 35:
		case 36:
			{
				money_heavycav = money_inf = money_arta = enemy_money/4;
				if (enemy_country_num == 35)
					money_arch = enemy_money/4;
				else
					money_eleph = enemy_money/4;
				enemy_troops["heavyhorseman"] += money_heavycav/get_heavycav_cost();
				enemy_troops["infantry"] += money_inf/get_inf_cost();
				enemy_troops["artillery"] += money_arta/get_arta_cost();
				if (enemy_country_num == 35)
				{
					enemy_troops["archers"] += money_arch/get_arch_cost();
					rest = (money_heavycav % get_heavycav_cost()) +  (money_inf % get_inf_cost()) + (money_arta % get_arta_cost()) + (money_arch % get_arch_cost());
					enemy_troops["archers"] += rest/get_arch_cost();
				}
				else
				{	
					enemy_troops["elephants"] += money_eleph/get_eleph_cost();
					rest = (money_heavycav % get_heavycav_cost()) +  (money_inf % get_inf_cost()) + (money_arta % get_arta_cost()) + (money_eleph % get_eleph_cost());
					enemy_troops["infantry"] += rest/get_inf_cost();
				}
				break;
			}
	}

}

Algorithms_EnemyCountry::Algorithms_EnemyCountry()
{
	enemy_troops["infantry"] = 0;
	enemy_troops["artillery"] = 0;
	enemy_troops["elephants"] = 0;
	enemy_troops["heavyhorseman"] = 0;
	enemy_troops["lighthorseman"] = 0;
	enemy_troops["archers"] = 0;
}

float Battle_Result::count_battle(string you, string enemy)
{
	float you_sc = 0;
	float enemy_sc = 0;
	
	pair<string, string> p(you, enemy);
	float country_effect = country_effects[p];
	
	float your_params = 0;
	float enemy_params = 0;
	map<string, float>::iterator it;
	for (it = parameters.begin(); it != parameters.end(); it++)
	{	
		your_params += (it->second)*static_cast<float>(troops[it->first]);
		enemy_params += (it->second)*static_cast<float>(enemy_troops[it->first]);
	}

	map<string, int>::iterator it2;
	map<string, int>::iterator it3;

	float your_coef = 1;
	float enemy_coef = 1;

	for (it2 = troops.begin(); it2 != troops.end(); it2++)
		for (it3 = enemy_troops.begin(); it3 != enemy_troops.end(); it3++)
		{	
			if (it2->second == 0 || it3->second == 0)
				continue;
			pair<string, string> pairy2(it2->first, it3->first);
			your_coef *= warrior_effects[pairy2];
			enemy_coef *= 1.0/warrior_effects[pairy2];
		}

	you_sc = country_effect*your_coef*your_params*(1.0 + your_score/10.0f);
	enemy_sc = (1.0f/country_effect)*enemy_coef*enemy_params*(1.0 + enemy_score/10.0f);

	if (you_sc == 0 || enemy_sc == 0)
		return 0;
	return you_sc > enemy_sc ? (you_sc/enemy_sc - 1.0f)*100.0f : -(enemy_sc/you_sc - 1.0f)*100.0f;
}

