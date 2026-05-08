#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include "../GL Files/include/GL/GLAux.h"
#include "../GL Files/include/GL/glut.h"

using namespace std;

const int width = 1024;
const int height = 680;

const int num_text_countries = 6; // six states
const int num_text_warriors_1 = 2; // two types of warriors in barbarian faction
const int num_text_warriors_2 = 3; // three - Carthage
const int num_text_warriors_3 = 2; // two - Egypt
const int num_text_warriors_4 = 2; // two - Parthia
const int num_text_warriors_5 = 4; // four - Rome
const int num_text_warriors_6 = 4; // four - Seleucids

extern bool choose_barbarians, choose_carthage, choose_egypt, choose_parthia, choose_rome, choose_seleucids;

class Textures
{
private :
	AUX_RGBImageRec	**taux_countries, // array of textures corresponding to countries
		**taux_1, **taux_2, **taux_3, **taux_4, **taux_5, **taux_6; // array of textures corresponding to warriors in whic country
	
	void loading_textures(); // initializing of textures

public :
	GLuint  *texName_countries, // array of ids corresponding to countries
		*texName_1, *texName_2, *texName_3, *texName_4, *texName_5, *texName_6; // array of ids corresponding to warriors in which country

	Textures(); // constructor
	~Textures(); //destructor
};

class Fonts
{

public :
	void print_bitmap_string(void* font, char* s) const;//function for printing bitmap symbols
	void print_stroke_string(void* font, char* s) const;//function for printing stroke symbols
	char* string_to_ptrchar(string str) const;
};

//this class unites functions relating to different game countries
class Countries
{	
protected:
	int your_score;
	int enemy_score;
public:
	map<pair<string, string>, float> country_effects;//map<pair<country, country>, effect>, the effects which one country influences at another
	enum _Countries {BARBARIANS, CARTHAGE, EGYPT, PARTHIA, ROME, SELEUCIDS, NONE};
	_Countries enum_countries;
	Countries ();
	void switch_off_flags() const;//switching off flags that mean countries
	void set_your_score(int);
	int get_your_score();
	void set_enemy_score(int);
	int get_enemy_score();
};

class Picture_Countries
{
public:
	bool is_Barbarians (int x, int y) const;//choosing Barbarians country and so on
	bool is_Carthage (int x, int y) const;
	bool is_Egypt (int x, int y) const;
	bool is_Parthia (int x, int y) const;
	bool is_Rome (int x, int y) const;
	bool is_Seleucids (int x, int y) const;
};

class Warriors
{
private:
	//costs of differnet types of warriors
	int inf_cost;
	int heavycav_cost;
	int lightcav_cost;
	int arta_cost;
	int eleph_cost;
	int arch_cost;
	int _money;//money for recruiting

protected:
	map<pair<string, string>, float> warrior_effects;//map<pair<warrior, warrior>, effect>, the effects which one type of warriors influences at another
	map<string, float> parameters;//parameters of each type of warriors

public:
	string money, rest_money;
	map<string, int> troops;//number of troops of each type
	Warriors();
	int get_inf_cost() const;
	int get_heavycav_cost() const;
	int get_lightcav_cost() const;
	int get_arta_cost() const;
	int get_eleph_cost() const;
	int get_arch_cost() const;

	void set_money(int money);
	int get_money() const;
};

class Picture_Warriors
{
private:
	int first_case, second_case, third_case;
public:
	Picture_Warriors();
	bool is_first_in_two(int x, int y) const;//first in two means we are choosing the first image of two. Same functions are further
	bool is_second_in_two(int x, int y) const;

	bool is_first_in_three(int x, int y) const;
	bool is_second_in_three(int x, int y) const;
	bool is_third_in_three(int x, int y) const;

	bool is_first_in_four(int x, int y) const;
	bool is_second_in_four(int x, int y) const;
	bool is_third_in_four(int x, int y) const;
	bool is_forth_in_four(int x, int y) const;

	int get_first_case() const;
	int get_second_case() const;
	int get_third_case() const;
};

class State
{
public:
	vector<pair <string, int> > states; //pair <string = state + country, id>
	State();
};

class Algorithms_EnemyCountry : public Warriors
{
public :
	map<string, int> enemy_troops;
	void alg_1(int enemy_country_num);
	Algorithms_EnemyCountry();
};

class Battle_Result : public Countries, public Algorithms_EnemyCountry
{
public:
	float count_battle(string, string);
};