#include "textures.h"

bool quit_available;
bool next_available, next_pressed;
bool return_available;
bool choose_country_available, choose_barbarians, choose_carthage, choose_egypt, choose_parthia, choose_rome, choose_seleucids;
bool check_time;
bool check_alg;
bool begin_enter_money;
bool end_enter_money;
bool spending_money;
bool rand_value;

Countries* countries;
Picture_Countries* pict_countries;
Textures* t;
Fonts* f;
Warriors* w;
Picture_Warriors* p_w;
State* state;
Algorithms_EnemyCountry* algy;
Battle_Result* battle;

///fonts
void* bitmap_fonts[7] = {
    GLUT_BITMAP_9_BY_15,
    GLUT_BITMAP_8_BY_13,
    GLUT_BITMAP_TIMES_ROMAN_10,
    GLUT_BITMAP_TIMES_ROMAN_24,
    GLUT_BITMAP_HELVETICA_10,
    GLUT_BITMAP_HELVETICA_12,
    GLUT_BITMAP_HELVETICA_18     
};

void* stroke_fonts[2] = {
      GLUT_STROKE_ROMAN,
      GLUT_STROKE_MONO_ROMAN
};

inline void delete_function()
{
	delete t;
	delete f;
	delete countries;
	delete w;
	delete pict_countries;
	delete p_w;
	delete state;
	delete algy;
	delete battle;
}

inline string floatToString(float f)
 {
    std::ostringstream ss;
    ss << f;
    return ss.str();
 }


void mouse (int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		if (choose_country_available)
		{	
			if (pict_countries->is_Barbarians(x, y))
				countries->enum_countries = countries->BARBARIANS;
			if (pict_countries->is_Carthage(x, y))
				countries->enum_countries = countries->CARTHAGE;
			if (pict_countries->is_Egypt(x, y))
				countries->enum_countries = countries->EGYPT;
			if (pict_countries->is_Parthia(x, y))
				countries->enum_countries = countries->PARTHIA;
			if (pict_countries->is_Rome(x, y))
				countries->enum_countries = countries->ROME;
			if (pict_countries->is_Seleucids(x, y))
				countries->enum_countries = countries->SELEUCIDS;
			glutPostRedisplay();
		}
		if (choose_barbarians || choose_egypt || choose_parthia)
		{	
			int rst_money = atoi(f->string_to_ptrchar(w->rest_money));
			if (p_w->is_first_in_two(x, y))
			{	
				char buf[20];
				if (rst_money >= w->get_heavycav_cost())
				{
					rst_money -= w->get_heavycav_cost();;
					w->troops["heavyhorseman"]++;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_second_in_two(x, y))
			{	
				char buf[20];
				if (rst_money >= w->get_inf_cost() && (choose_barbarians || choose_egypt))
				{
					rst_money -= w->get_inf_cost();
					w->troops["infantry"]++;
					w->rest_money = itoa(rst_money, buf, 10);
				}
				if (rst_money >= w->get_lightcav_cost() && choose_parthia)
				{
					rst_money -= w->get_lightcav_cost();
					w->troops["lighthorseman"]++;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
		}
		if (choose_carthage)
		{	
			int rst_money = atoi(f->string_to_ptrchar(w->rest_money));
			if (p_w->is_first_in_three(x, y))
			{	
				char buf[20];
				if (rst_money >= w->get_heavycav_cost())
				{
					rst_money -= w->get_heavycav_cost();
					w->troops["heavyhorseman"]++;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_second_in_three(x, y))
			{	
				char buf[20];
				if (rst_money >= w->get_eleph_cost())
				{
					rst_money -= w->get_eleph_cost();
					w->troops["elephants"]++;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_third_in_three(x, y))
			{	
				char buf[20];
				if (rst_money >= w->get_inf_cost())
				{
					rst_money -= w->get_inf_cost();
					w->troops["infantry"]++;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
		}
		if (choose_rome || choose_seleucids)
		{
			int rst_money = atoi(f->string_to_ptrchar(w->rest_money));
			if (p_w->is_first_in_four(x, y))
			{	
				char buf[20];
				if (rst_money >= w->get_arta_cost())
				{
					rst_money -= w->get_arta_cost();
					w->troops["artillery"]++;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_second_in_four(x, y))
			{	
				char buf[20];
				if (rst_money >= w->get_heavycav_cost())
				{
					rst_money -= w->get_heavycav_cost();
					w->troops["heavyhorseman"]++;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_third_in_four(x, y))
			{	
				char buf[20];
				if (rst_money >= w->get_arch_cost() && choose_rome)
				{
					rst_money -= w->get_arch_cost();
					w->troops["archers"]++;
					w->rest_money = itoa(rst_money, buf, 10);
				}
				if (rst_money >= w->get_eleph_cost() && choose_seleucids)
				{
					rst_money -= w->get_eleph_cost();
					w->troops["elephants"]++;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_forth_in_four(x, y))
			{	
				char buf[20];
				if (rst_money >= w->get_inf_cost())
				{
					rst_money -= w->get_inf_cost();
					w->troops["infantry"]++;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
		}
		glutPostRedisplay();
	}
	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN))
	{
		if (choose_barbarians || choose_egypt || choose_parthia)
		{	
			int rst_money = atoi(f->string_to_ptrchar(w->rest_money));		
			if (p_w->is_first_in_two(x, y))
			{	
				char buf[20];
				if (w->troops["heavyhorseman"] > 0)
				{
					rst_money += w->get_heavycav_cost();;
					w->troops["heavyhorseman"]--;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_second_in_two(x, y))
			{	
				char buf[20];
				if (w->troops["infantry"] > 0 && (choose_barbarians || choose_egypt))
				{
					rst_money += w->get_inf_cost();
					w->troops["infantry"]--;
					w->rest_money = itoa(rst_money, buf, 10);
				}
				if (w->troops["lighthorseman"] > 0 && choose_parthia)
				{
					rst_money += w->get_lightcav_cost();
					w->troops["lighthorseman"]--;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}

		}
		if (choose_carthage)
		{	
			int rst_money = atoi(f->string_to_ptrchar(w->rest_money));
			if (p_w->is_first_in_three(x, y))
			{	
				char buf[20];
				if (w->troops["heavyhorseman"] > 0)
				{
					rst_money += w->get_heavycav_cost();
					w->troops["heavyhorseman"]--;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_second_in_three(x, y))
			{	
				char buf[20];
				if (w->troops["elephants"] > 0)
				{
					rst_money += w->get_eleph_cost();
					w->troops["elephants"]--;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_third_in_three(x, y))
			{	
				char buf[20];
				if (w->troops["infantry"] > 0)
				{
					rst_money += w->get_inf_cost();
					w->troops["infantry"]--;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
		}
		if (choose_rome || choose_seleucids)
		{
			int rst_money = atoi(f->string_to_ptrchar(w->rest_money));
			if (p_w->is_first_in_four(x, y))
			{	
				char buf[20];
				if (w->troops["artillery"] > 0)
				{
					rst_money += w->get_arta_cost();
					w->troops["artillery"]--;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_second_in_four(x, y))
			{	
				char buf[20];
				if (w->troops["heavyhorseman"] > 0)
				{
					rst_money += w->get_heavycav_cost();
					w->troops["heavyhorseman"]--;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_third_in_four(x, y))
			{	
				char buf[20];
				if (w->troops["archers"] > 0 && choose_rome)
				{
					rst_money += w->get_arch_cost();
					w->troops["archers"]--;
					w->rest_money = itoa(rst_money, buf, 10);
				}
				if (w->troops["elephants"] > 0 && choose_seleucids)
				{
					rst_money += w->get_eleph_cost();
					w->troops["elephants"]--;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
			if (p_w->is_forth_in_four(x, y))
			{	
				char buf[20];
				if (w->troops["infantry"] > 0)
				{
					rst_money += w->get_inf_cost();
					w->troops["infantry"]--;
					w->rest_money = itoa(rst_money, buf, 10);
				}
			}
		}
		glutPostRedisplay();
	}
}

void keyboard(unsigned char key, int x, int y) {
		
	if (quit_available && (key == 'Q' || key == 'q'))
	{	
		exit(0);
		glutPostRedisplay();
	}
	if (next_available && (key == 'N' || key == 'n'))
	{	
		next_pressed = true;
		glutPostRedisplay();
	}
	if (return_available && (key == 'B' || key == 'b'))
	{	
		state->states.pop_back();
		glutPostRedisplay();
	}

	//key == 8 is backspace
	if (end_enter_money && key == 8)
		end_enter_money = false;

	if (!end_enter_money && begin_enter_money)
	{
		if ((key == 8) && (!w->money.empty()))
			w->money.pop_back();
		else
		{
			if (w->money.empty())
				w->money.clear();
			//key == 32 is space
			if ((key == 32) && (!w->money.empty()))
				end_enter_money = true;
			//if user is pressing the digit and money amount is less than
			else if ((key >= 48) && (key <= 57) && (atoi(f->string_to_ptrchar(w->money)) < 10000000))
			{	
				if (key == 48 && w->money.empty())
				{}
				else
					w->money += key;
				if (atoi(f->string_to_ptrchar(w->money)) >= 50000)
					w->money = "50000";
			}
		}
		glutPostRedisplay();
	}

}

void reshape (int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	int second_value = state->states[state->states.size() - 1].second;

	glColor3f(1.0, 1.0, 1.0);

	switch (second_value)
	{
		//intro
		case 0 :
		{
			glBindTexture(GL_TEXTURE_2D, t->texName_countries[5]);

			glBegin(GL_QUADS);
			glTexCoord2i(0, 0); glVertex2i(0, 0);
			glTexCoord2i(0, 1); glVertex2i(0, height);
			glTexCoord2i(1, 1); glVertex2i(width, height);
			glTexCoord2i(1, 0); glVertex2i(width, 0);
			glEnd();
			
			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			glLineWidth(13.0);
			glTranslated(50, height - height/4, 0);
			glScalef(1.71,1.36,1.0);
			f->print_stroke_string(stroke_fonts[0], "ANCIENT");
			glPopMatrix();

			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			glLineWidth(13.0);
			glTranslated(50, height - 3*height/4, 0);
			glScalef(1.65,1.36,1.0);
			f->print_stroke_string(stroke_fonts[0], "BATTLES");
			glPopMatrix();

			pair<string, int> p("menu none", 1);
			state->states.push_back(p);
			glutPostRedisplay();
			break;
		};
		//main menu
		case 1 :
		{
			if (check_time)
			{
				Sleep(3600);
				check_time = false;
			}

			glBindTexture(GL_TEXTURE_2D, t->texName_countries[5]);

			glBegin(GL_QUADS);
			glTexCoord2i(0, 0); glVertex2i(0, 0);
			glTexCoord2i(0, 1); glVertex2i(0, height);
			glTexCoord2i(1, 1); glVertex2i(width, height);
			glTexCoord2i(1, 0); glVertex2i(width, 0);
			glEnd();

			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			glLineWidth(5.0);
			glTranslated(width/2 - 300, height/2 + 100, 0);
			glScalef(0.4,0.4,1.0);
			f->print_stroke_string(stroke_fonts[0], "New game (press N)");
			glPopMatrix();

			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			glLineWidth(5.0);
			glTranslated(width/2 - 300, height/2, 0);
			glScalef(0.4,0.4,1.0);
			f->print_stroke_string(stroke_fonts[0], "Quit game (press Q)");
			glPopMatrix();
			
			quit_available = next_available = true;
			return_available = false;
			choose_country_available = false;

			if (next_pressed)
			{
				pair<string, int> p("new_gane_menu none", 2);
				state->states.push_back(p);
				next_pressed = false;
				glutPostRedisplay();
			}
			break;
		};
		//choosing the state mode
		case 3 :
		case 2 :
			{
				next_available = quit_available = false;

				glBindTexture(GL_TEXTURE_2D, t->texName_countries[0]);

				glBegin(GL_QUADS);
				glTexCoord2i(0, 0); glVertex2i(0, height - 290);
				glTexCoord2i(0, 1); glVertex2i(0, height);
				glTexCoord2i(1, 1); glVertex2i(width/3, height);
				glTexCoord2i(1, 0); glVertex2i(width/3, height - 290);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, t->texName_countries[1]);

				glBegin(GL_QUADS);
				glTexCoord2i(0, 0); glVertex2i(width/3 + 1, height - 290);
				glTexCoord2i(0, 1); glVertex2i(width/3 + 1, height);
				glTexCoord2i(1, 1); glVertex2i(2*width/3, height);
				glTexCoord2i(1, 0); glVertex2i(2*width/3, height - 290);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, t->texName_countries[2]);

				glBegin(GL_QUADS);
				glTexCoord2i(0, 0); glVertex2i(2*width/3 + 1, height - 290);
				glTexCoord2i(0, 1); glVertex2i(2*width/3 + 1, height);
				glTexCoord2i(1, 1); glVertex2i(width, height);
				glTexCoord2i(1, 0); glVertex2i(width, height - 290);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, t->texName_countries[3]);

				glBegin(GL_QUADS);
				glTexCoord2i(0, 0); glVertex2i(0, 100);
				glTexCoord2i(0, 1); glVertex2i(0, height - 290);
				glTexCoord2i(1, 1); glVertex2i(width/3, height - 290);
				glTexCoord2i(1, 0); glVertex2i(width/3, 100);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, t->texName_countries[4]);

				glBegin(GL_QUADS);
				glTexCoord2i(0, 0); glVertex2i(width/3 + 1, 100);
				glTexCoord2i(0, 1); glVertex2i(width/3 + 1, height - 290);
				glTexCoord2i(1, 1); glVertex2i(2*width/3, height - 290);
				glTexCoord2i(1, 0); glVertex2i(2*width/3, 100);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, t->texName_countries[5]);

				glBegin(GL_QUADS);
				glTexCoord2i(0, 0); glVertex2i(2*width/3 + 1, 100);
				glTexCoord2i(0, 1); glVertex2i(2*width/3 + 1, height - 290);
				glTexCoord2i(1, 1); glVertex2i(width, height - 290);
				glTexCoord2i(1, 0); glVertex2i(width, 100);
				glEnd();

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(50, 25, 0);
				glScalef(0.28,0.34,1.0);
				if (second_value == 2)
					f->print_stroke_string(stroke_fonts[0], "Click on your country. For return press B");
				else
					f->print_stroke_string(stroke_fonts[0], "Click on enemy country. For return press B");
				glPopMatrix();
				
				///
				glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10, height - 145, 0);
				glScalef(0.5,0.5,1.0);
				f->print_stroke_string(stroke_fonts[0], "Barbarians");
				glPopMatrix();

				glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 + width/3, height - 145, 0);
				glScalef(0.5,0.5,1.0);
				f->print_stroke_string(stroke_fonts[0], "Carthage");
				glPopMatrix();

				glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 + 2*width/3, height - 145, 0);
				glScalef(0.5,0.5,1.0);
				f->print_stroke_string(stroke_fonts[0], "Egypt");
				glPopMatrix();

				glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 , height - 435, 0);
				glScalef(0.5,0.5,1.0);
				f->print_stroke_string(stroke_fonts[0], "Parthia");
				glPopMatrix();

				glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 + width/3 , height - 435, 0);
				glScalef(0.5,0.5,1.0);
				f->print_stroke_string(stroke_fonts[0], "Rome");
				glPopMatrix();

				glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 + 2*width/3 , height - 435, 0);
				glScalef(0.5,0.5,1.0);
				f->print_stroke_string(stroke_fonts[0], "Seleucids");
				glPopMatrix();
				
				return_available = true;
				choose_country_available = true;

				switch(countries->enum_countries)
				{
					case countries->BARBARIANS : 
					{
						if (second_value == 2)
						{	
							pair<string, int> p("barbarians", 21);
							state->states.push_back(p);
						}
						else
						{
							pair<string, int> p("barbarians", 31);
							state->states.push_back(p);
						}
						break;
					};
					case countries->CARTHAGE : 
					{
						if (second_value == 2)
						{	
							pair<string, int> p("carthage", 22);
							state->states.push_back(p);
						}
						else
						{
							pair<string, int> p("carthage", 32);
							state->states.push_back(p);
						}
						break;
					};
					case countries->EGYPT :
					{	
						if (second_value == 2)
						{	
							pair<string, int> p("egypt", 23);
							state->states.push_back(p);
						}
						else
						{
							pair<string, int> p("egypt", 33);
							state->states.push_back(p);
						}
						break;
					};
					case countries->PARTHIA :
					{	
						if (second_value == 2)
						{	
							pair<string, int> p("parthia", 24);
							state->states.push_back(p);
						}
						else
						{
							pair<string, int> p("parthia", 34);
							state->states.push_back(p);
						}
						break;
					};
					case countries->ROME :
					{	
						if (second_value == 2)
						{	
							pair<string, int> p("rome", 25);
							state->states.push_back(p);
						}
						else
						{
							pair<string, int> p("rome", 35);
							state->states.push_back(p);
						}
						break;
					};
					case countries->SELEUCIDS :
					{	
						if (second_value == 2)
						{	
							pair<string, int> p("seleucids", 26);
							state->states.push_back(p);
						}
						else
						{
							pair<string, int> p("seleucids", 36);
							state->states.push_back(p);
						}
						break;
					};
				};
				countries->enum_countries = countries->NONE;
				glutPostRedisplay();
				break;
			};
		//finish of choosing state mode
		case 31:
		case 32:
		case 33:
		case 34:
		case 35:
		case 36:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
			{
				choose_country_available = false;
				next_available = true;
				w->money.clear();

				glColor3f(1.0, 1.0, 1.0);

				glBindTexture(GL_TEXTURE_2D, t->texName_countries[second_value % 10 - 1]);

				glBegin(GL_QUADS);
				glTexCoord2i(0, 0); glVertex2i(0, 100);
				glTexCoord2i(0, 1); glVertex2i(0, height);
				glTexCoord2i(1, 1); glVertex2i(width, height);
				glTexCoord2i(1, 0); glVertex2i(width, 100);
				glEnd();
				
				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 , 75, 0);
				glScalef(0.2,0.2,1.0);
				switch (second_value)
				{
					case 31 : 
					case 21 :
						{
							f->print_stroke_string(stroke_fonts[0], "You've chosen the Barbarians country.");
							break;
						};
					case 32 :
					case 22 :
						{
							f->print_stroke_string(stroke_fonts[0], "You've chosen the Carthage country.");
							break;
						};
					case 33 :
					case 23 :
						{
							f->print_stroke_string(stroke_fonts[0], "You've chosen the Egypt country.");
							break;
						};
					case 34 :
					case 24 :
						{
							f->print_stroke_string(stroke_fonts[0], "You've chosen the Parthia country.");
							break;
						};
				    case 35 :
					case 25 :
						{
							f->print_stroke_string(stroke_fonts[0], "You've chosen the Rome country.");
							break;
						};
					case 36 :
					case 26 :
						{
							f->print_stroke_string(stroke_fonts[0], "You've chosen the Seleucids country.");
							break;
						};
				}
				glPopMatrix();

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 , 25, 0);
				glScalef(0.2,0.2,1.0);
				
				switch (second_value)
				{
					case 21:
					case 22:
					case 23:
					case 24:
					case 25:
					case 26: 
						{
							f->print_stroke_string(stroke_fonts[0], "Press B for going back, N - for choosing enemy");
							if (next_pressed)
							{
								pair<string, int> p("your_country_is chosen", 3);
								state->states.push_back(p);
								next_pressed = false;
							}
							break;
						};
					case 31:
					case 32:
					case 33:
					case 34:
					case 35:
					case 36: 
						{
							f->print_stroke_string(stroke_fonts[0], "Choosing completed. Press B for going back, N - for going further");
							if (next_pressed)
							{
								pair<string, int> p("all_sides_are chosen", 4);
								state->states.push_back(p);
								next_pressed = false;
							}
							break;
						};
				}
				glPopMatrix();
				end_enter_money = false;
				glutPostRedisplay();
				break;
			};
		//entering the num of money
		case 4 :
			{
				next_available = false;
				spending_money = check_alg = true;
				for (map<string, int>::iterator it = w->troops.begin(); it != w->troops.end(); it++)
					it->second = 0;
				glBindTexture(GL_TEXTURE_2D, t->texName_countries[state->states[state->states.size() - 4].second % 10 - 1]);

				glBegin(GL_QUADS);
				glTexCoord2i(0, 0); glVertex2i(0, height/2 + 75);
				glTexCoord2i(0, 1); glVertex2i(0, height);
				glTexCoord2i(1, 1); glVertex2i(width, height);
				glTexCoord2i(1, 0); glVertex2i(width, height/2 + 75);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, t->texName_countries[state->states[state->states.size() - 2].second % 10 - 1]);

				glBegin(GL_QUADS);
				glTexCoord2i(0, 0); glVertex2i(0, 150);
				glTexCoord2i(0, 1); glVertex2i(0, height/2 + 75);
				glTexCoord2i(1, 1); glVertex2i(width, height/2 + 75);
				glTexCoord2i(1, 0); glVertex2i(width, 150);
				glEnd();

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 , 125, 0);
				glScalef(0.2,0.2,1.0);
				switch (state->states[state->states.size() - 4].second)
				{
					case 21 :
						{
							f->print_stroke_string(stroke_fonts[0], "Your country is Barbarians.");
							break;
						};
					case 22 :
						{
							f->print_stroke_string(stroke_fonts[0], "Your country is Carthage.");
							break;
						};
					case 23 :
						{
							f->print_stroke_string(stroke_fonts[0], "Your country is Egypt.");
							break;
						};
					case 24 :
						{
							f->print_stroke_string(stroke_fonts[0], "Your country is Parthia.");
							break;
						};
					case 25 :
						{
							f->print_stroke_string(stroke_fonts[0], "Your country is Rome.");
							break;
						};
					case 26 :
						{
							f->print_stroke_string(stroke_fonts[0], "Your country is Seleucids.");
							break;
						};
				}
				glPopMatrix();

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(width/2, 125, 0);
				glScalef(0.2,0.2,1.0);
				switch (state->states[state->states.size() - 2].second)
				{
					case 31 :
						{
							f->print_stroke_string(stroke_fonts[0], "Enemy's country is Barbarians.");
							break;
						};
					case 32 :
						{
							f->print_stroke_string(stroke_fonts[0], "Enemy's country is Carthage.");
							break;
						};
					case 33 :
						{
							f->print_stroke_string(stroke_fonts[0], "Enemy's country is Egypt.");
							break;
						};
					case 34 :
						{
							f->print_stroke_string(stroke_fonts[0], "Enemy's country is Parthia.");
							break;
						};
					case 35 :
						{
							f->print_stroke_string(stroke_fonts[0], "Enemy's country is Rome.");
							break;
						};
					case 36 :
						{
							f->print_stroke_string(stroke_fonts[0], "Enemy's country is Seleucids.");
							break;
						};
				}

				glPopMatrix();

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 , 75, 0);
				glScalef(0.17,0.17,1.0);
				f->print_stroke_string(stroke_fonts[0], "Enter money until pressing space key. After that press B for return, N - going further");
				glPopMatrix();
				
				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 , 25, 0);
				glScalef(0.19,0.19,1.0);
				f->print_stroke_string(stroke_fonts[0], "Warning : not only cost or power of unit matters, there is also the balance.");
				glPopMatrix();

				begin_enter_money = true;

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(9.0);
				glTranslated(10 , height/2, 0);
				glScalef(0.9,0.9,1.0);
				string str = w->money + " denaries.";
				if (w->money == "")
					f->print_stroke_string(stroke_fonts[0], "0 denaries");
				else
					f->print_stroke_string(stroke_fonts[0], f->string_to_ptrchar(str));
				glPopMatrix();

				if (end_enter_money)
				{	
					w->set_money(atoi(f->string_to_ptrchar(w->money)));
					algy->set_money(w->get_money());
					next_available = true;
				}

				if (next_pressed)
				{
					pair<string, int> p("money_is chosen", 5);
					state->states.push_back(p);
					next_pressed = false;
				}

				glutPostRedisplay();
				break;
			};
		//recruiting of troops
		case 5 :
			{
				int num_country = state->states[state->states.size() - 5].second;
				if (spending_money)
				{
					w->rest_money = w->money;
					spending_money = false;
				}
				countries->switch_off_flags();
				switch (num_country)
				{
					//Barbarians, Egypt
					case 21:
					case 23 :
						{
							if (num_country == 21)
							{
								choose_barbarians = true;
								for (int i = 0; i < 2; ++i)
								{
									glBindTexture(GL_TEXTURE_2D, t->texName_1[i]);

									glBegin(GL_QUADS);
									glTexCoord2i(0, 0); glVertex2i(i*width/2, 250);
									glTexCoord2i(0, 1); glVertex2i(i*width/2, height);
									glTexCoord2i(1, 1); glVertex2i((i + 1)*width/2, height);
									glTexCoord2i(1, 0); glVertex2i((i + 1)*width/2, 250);
									glEnd();
								}
							}
							else
							{
								choose_egypt = true;
								for (int i = 0; i < 2; ++i)
								{
									glBindTexture(GL_TEXTURE_2D, t->texName_3[i]);

									glBegin(GL_QUADS);
									glTexCoord2i(0, 0); glVertex2i(i*width/2, 250);
									glTexCoord2i(0, 1); glVertex2i(i*width/2, height);
									glTexCoord2i(1, 1); glVertex2i((i + 1)*width/2, height);
									glTexCoord2i(1, 0); glVertex2i((i + 1)*width/2, 250);
									glEnd();
								}
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Horseman. 1000 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/2 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Infantry. 500 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 24");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/2 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 18");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 75, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "You have ");
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], f->string_to_ptrchar(w->rest_money));
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], " denaries.");
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], " Click on the warrior for buying.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 25, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Press B for return, N - for going further.");
							glTranslated(50, 0, 0);
							if (num_country == 21)
							{
								f->print_stroke_string(stroke_fonts[0], "Your country is Barbarians");
							}
							else
							{
								f->print_stroke_string(stroke_fonts[0], "Your country is Egypt");
							}
							glPopMatrix();

							char cav[20];
							char inf[20];

							itoa(w->troops["heavyhorseman"], cav, 10);
							itoa(w->troops["infantry"], inf, 10);

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(width/4 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], cav);
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(3*width/4 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], inf);
							glPopMatrix();

							break;
						};
					//Carthage
					case 22 :
						{
							choose_carthage = true;
							for (int i = 0; i < 3; ++i)
							{
								glBindTexture(GL_TEXTURE_2D, t->texName_2[i]);

								glBegin(GL_QUADS);
								glTexCoord2i(0, 0); glVertex2i(i*width/3, 250);
								glTexCoord2i(0, 1); glVertex2i(i*width/3, height);
								glTexCoord2i(1, 1); glVertex2i((i + 1)*width/3, height);
								glTexCoord2i(1, 0); glVertex2i((i + 1)*width/3, 250);
								glEnd();
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 175, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Horseman. 1000 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/3 , 175, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Elephants. 1500 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + 2*width/3 , 175, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Infantry. 500 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 125, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 24");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/3 , 125, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 28");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + 2*width/3 , 125, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 18");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 75, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "You have ");
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], f->string_to_ptrchar(w->rest_money));
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], " denaries.");
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], " Click on the warrior for buying.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 25, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Press B for return, N - for going further.");
							glTranslated(50, 0, 0);
							f->print_stroke_string(stroke_fonts[0], "Your country is Carthage");
							glPopMatrix();

							char cav[20];
							char inf[20];
							char eleph[20];

							itoa(w->troops["heavyhorseman"], cav, 10);
							itoa(w->troops["infantry"], inf, 10);
							itoa(w->troops["elephants"], eleph, 10);

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(width/6 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], cav);
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(width/2 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], eleph);
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(5*width/6 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], inf);
							glPopMatrix();

							break;
						};
					//Parthia
					case 24 :
						{
							choose_parthia = true;
							for (int i = 0; i < 2; ++i)
							{
								glBindTexture(GL_TEXTURE_2D, t->texName_4[i]);

								glBegin(GL_QUADS);
								glTexCoord2i(0, 0); glVertex2i(i*width/2, 250);
								glTexCoord2i(0, 1); glVertex2i(i*width/2, height);
								glTexCoord2i(1, 1); glVertex2i((i + 1)*width/2, height);
								glTexCoord2i(1, 0); glVertex2i((i + 1)*width/2, 250);
								glEnd();
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Heavy horseman. 1000 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/2 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Light horseman. 1200 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 24");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/2 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 28");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 75, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "You have ");
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], f->string_to_ptrchar(w->rest_money));
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], " denaries.");
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], " Click on the warrior for buying.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 25, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Press B for return, N - for going further.");
							glTranslated(50, 0, 0);
							f->print_stroke_string(stroke_fonts[0], "Your country is Parthia");
							glPopMatrix();

							char heavy_cav[20];
							char light_cav[20];

							itoa(w->troops["heavyhorseman"], heavy_cav, 10);
							itoa(w->troops["lighthorseman"], light_cav, 10);

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(width/4 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], heavy_cav);
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(3*width/4 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], light_cav);
							glPopMatrix();

							break;
						};
					//Rome, Seleucicds
					case 25 :
					case 26:
						{
							if (num_country == 25)
							{
								choose_rome = true;
								for (int i = 0; i < 4; ++i)
								{
									glBindTexture(GL_TEXTURE_2D, t->texName_5[i]);

									glBegin(GL_QUADS);
									glTexCoord2i(0, 0); glVertex2i(i*width/4, 300);
									glTexCoord2i(0, 1); glVertex2i(i*width/4, height);
									glTexCoord2i(1, 1); glVertex2i((i + 1)*width/4, height);
									glTexCoord2i(1, 0); glVertex2i((i + 1)*width/4, 300);
									glEnd();
								}
							}
							else
							{
								choose_seleucids = true;
								for (int i = 0; i < 4; ++i)
								{
									glBindTexture(GL_TEXTURE_2D, t->texName_6[i]);

									glBegin(GL_QUADS);
									glTexCoord2i(0, 0); glVertex2i(i*width/4, 300);
									glTexCoord2i(0, 1); glVertex2i(i*width/4, height);
									glTexCoord2i(1, 1); glVertex2i((i + 1)*width/4, height);
									glTexCoord2i(1, 0); glVertex2i((i + 1)*width/4, 300);
									glEnd();
								}
							}
							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 225, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Artillery.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/4 , 225, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Horseman.");
							glPopMatrix();

							if (num_country == 25)
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 225, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "Archer.");
								glPopMatrix();
							}
							else
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 225, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "Elephants.");
								glPopMatrix();
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + 3*width/4 , 225, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Infantry.");
							glPopMatrix();

							///

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "900 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/4 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "1000 denaries.");
							glPopMatrix();

							if (num_country == 25)
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 175, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "400 denaries.");
								glPopMatrix();
							}
							else
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 175, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "1500 denaries.");
								glPopMatrix();
							}


							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + 3*width/4 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "500 denaries.");
							glPopMatrix();

							///

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 20");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/4 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 24");
							glPopMatrix();

							if (num_country == 25)
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 125, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "Power - 17");
								glPopMatrix();
							}
							else
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 125, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "Power - 28");
								glPopMatrix();
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + 3*width/4 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 18");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 75, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "You have ");
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], f->string_to_ptrchar(w->rest_money));
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], " denaries.");
							glTranslated(50 , 0, 0);
							f->print_stroke_string(stroke_fonts[0], " Click on the warrior for buying.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 25, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Press B for return, N - for going further.");
							glTranslated(50, 0, 0);
							if (num_country == 25)
							{
								f->print_stroke_string(stroke_fonts[0], "Your country is Rome");
							}
							else
							{
								f->print_stroke_string(stroke_fonts[0], "Your country is Seleucids");
							}
							glPopMatrix();

							char heavy_cav[20];
							char inf[20];
							char arta[20];
							char arch[20];
							char eleph[20];

							itoa(w->troops["heavyhorseman"], heavy_cav, 10);
							itoa(w->troops["infantry"], inf, 10);
							itoa(w->troops["artillery"], arta, 10);
							itoa(w->troops["archers"], arch, 10);
							itoa(w->troops["elephants"], eleph, 10);

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(width/8 , 260, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], arta);
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(3*width/8 , 260, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], heavy_cav);
							glPopMatrix();

							if (num_country == 25)
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(5*width/8 , 260, 0);
								glScalef(0.3,0.3,1.0);
								f->print_stroke_string(stroke_fonts[0], arch);
								glPopMatrix();
							}
							else
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(5*width/8 , 260, 0);
								glScalef(0.3,0.3,1.0);
								f->print_stroke_string(stroke_fonts[0], eleph);
								glPopMatrix();
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(7*width/8 , 260, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], inf);
							glPopMatrix();
							break;
						};
			}
			if (next_pressed)
			{
				pair<string, int> p("warriors recruited", 6);
				state->states.push_back(p);
				next_pressed = false;
			}
			glutPostRedisplay();
			break;
		};
		//enemy's recruiting
		case 6:
			{
				int enemy_country = state->states[state->states.size() - 4].second;
				if (check_alg)
				{	
					algy->alg_1(enemy_country);
					check_alg = false;
				}
				pair<string, string> p(state->states[state->states.size() - 6].first, state->states[state->states.size() - 4].first);//pair<your country, enemy's country>
				countries->switch_off_flags();
				switch(enemy_country)
				{
					//Barbarians, Egypt
					case 31:
					case 33:
						{
							if (enemy_country == 31)
							{
								for (int i = 0; i < 2; ++i)
								{
									glBindTexture(GL_TEXTURE_2D, t->texName_1[i]);

									glBegin(GL_QUADS);
									glTexCoord2i(0, 0); glVertex2i(i*width/2, 250);
									glTexCoord2i(0, 1); glVertex2i(i*width/2, height);
									glTexCoord2i(1, 1); glVertex2i((i + 1)*width/2, height);
									glTexCoord2i(1, 0); glVertex2i((i + 1)*width/2, 250);
									glEnd();
								}
							}
							else
							{
								for (int i = 0; i < 2; ++i)
								{
									glBindTexture(GL_TEXTURE_2D, t->texName_3[i]);

									glBegin(GL_QUADS);
									glTexCoord2i(0, 0); glVertex2i(i*width/2, 250);
									glTexCoord2i(0, 1); glVertex2i(i*width/2, height);
									glTexCoord2i(1, 1); glVertex2i((i + 1)*width/2, height);
									glTexCoord2i(1, 0); glVertex2i((i + 1)*width/2, 250);
									glEnd();
								}
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Horseman. 1000 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/2 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Infantry. 500 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 24");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/2 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 18");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 75, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Enemy's warriors are chosen. You have ");
							glTranslated(50, 0, 0);
							f->print_stroke_string(stroke_fonts[0], f->string_to_ptrchar(floatToString((countries->country_effects[p] - 1.0f)*100.0f)));
							glTranslated(50, 0, 0);
							if (enemy_country == 31)
								f->print_stroke_string(stroke_fonts[0],"% upon Barbarians.");
							else
								f->print_stroke_string(stroke_fonts[0],"% upon Egypt.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 25, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Press B for return, N - for going to counting scores for battle.");
							glPopMatrix();

							char cav[20];
							char inf[20];

							itoa(algy->enemy_troops["heavyhorseman"], cav, 10);
							itoa(algy->enemy_troops["infantry"], inf, 10);

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(width/4 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], cav);
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(3*width/4 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], inf);
							glPopMatrix();
							break;
						};
					//Carthage
					case 32:
						{
							for (int i = 0; i < 3; ++i)
							{
								glBindTexture(GL_TEXTURE_2D, t->texName_2[i]);

								glBegin(GL_QUADS);
								glTexCoord2i(0, 0); glVertex2i(i*width/3, 250);
								glTexCoord2i(0, 1); glVertex2i(i*width/3, height);
								glTexCoord2i(1, 1); glVertex2i((i + 1)*width/3, height);
								glTexCoord2i(1, 0); glVertex2i((i + 1)*width/3, 250);
								glEnd();
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 175, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Horseman. 1000 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/3 , 175, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Elephants. 1500 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + 2*width/3 , 175, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Infantry. 500 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 125, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 24");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/3 , 125, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 28");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + 2*width/3 , 125, 0);
							glScalef(0.17,0.17,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 18");
							glPopMatrix();
							
							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 75, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Enemy's warriors are chosen. You have ");
							glTranslated(50, 0, 0);
							f->print_stroke_string(stroke_fonts[0], f->string_to_ptrchar(floatToString((countries->country_effects[p] - 1.0f)*100.0f)));
							glTranslated(50, 0, 0);
							f->print_stroke_string(stroke_fonts[0],"% upon Carthage.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 25, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Press B for return, N - for going to counting scores for battle.");
							glPopMatrix();

							char cav[20];
							char inf[20];
							char eleph[20];

							itoa(algy->enemy_troops["heavyhorseman"], cav, 10);
							itoa(algy->enemy_troops["infantry"], inf, 10);
							itoa(algy->enemy_troops["elephants"], eleph, 10);

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(width/6 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], cav);
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(width/2 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], eleph);
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(5*width/6 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], inf);
							glPopMatrix();
							break;
						};
					//Parthia
					case 34:
						{
							for (int i = 0; i < 2; ++i)
							{
								glBindTexture(GL_TEXTURE_2D, t->texName_4[i]);

								glBegin(GL_QUADS);
								glTexCoord2i(0, 0); glVertex2i(i*width/2, 250);
								glTexCoord2i(0, 1); glVertex2i(i*width/2, height);
								glTexCoord2i(1, 1); glVertex2i((i + 1)*width/2, height);
								glTexCoord2i(1, 0); glVertex2i((i + 1)*width/2, 250);
								glEnd();
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Heavy horseman. 1000 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/2 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Light horseman. 1200 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 24");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/2 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 28");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 75, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Enemy's warriors are chosen. You have ");
							glTranslated(50, 0, 0);
							f->print_stroke_string(stroke_fonts[0], f->string_to_ptrchar(floatToString((countries->country_effects[p] - 1.0f)*100.0f)));
							glTranslated(50, 0, 0);
							f->print_stroke_string(stroke_fonts[0],"% upon Parthia.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 25, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Press B for return, N - for going to counting scores for battle.");
							glPopMatrix();

							char heavy_cav[20];
							char light_cav[20];

							itoa(algy->enemy_troops["heavyhorseman"], heavy_cav, 10);
							itoa(algy->enemy_troops["lighthorseman"], light_cav, 10);

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(width/4 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], heavy_cav);
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(3*width/4 , 210, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], light_cav);
							glPopMatrix();
							break;
						};
					//Rome, Seleucids
					case 35:
					case 36:
						{
							if (enemy_country == 35)
							{
								for (int i = 0; i < 4; ++i)
								{
									glBindTexture(GL_TEXTURE_2D, t->texName_5[i]);

									glBegin(GL_QUADS);
									glTexCoord2i(0, 0); glVertex2i(i*width/4, 300);
									glTexCoord2i(0, 1); glVertex2i(i*width/4, height);
									glTexCoord2i(1, 1); glVertex2i((i + 1)*width/4, height);
									glTexCoord2i(1, 0); glVertex2i((i + 1)*width/4, 300);
									glEnd();
								}
							}
							else
							{
								for (int i = 0; i < 4; ++i)
								{
									glBindTexture(GL_TEXTURE_2D, t->texName_6[i]);

									glBegin(GL_QUADS);
									glTexCoord2i(0, 0); glVertex2i(i*width/4, 300);
									glTexCoord2i(0, 1); glVertex2i(i*width/4, height);
									glTexCoord2i(1, 1); glVertex2i((i + 1)*width/4, height);
									glTexCoord2i(1, 0); glVertex2i((i + 1)*width/4, 300);
									glEnd();
								}
							}
							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 225, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Artillery.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/4 , 225, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Horseman.");
							glPopMatrix();

							if (enemy_country == 35)
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 225, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "Archer.");
								glPopMatrix();
							}
							else
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 225, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "Elephants.");
								glPopMatrix();
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + 3*width/4 , 225, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Infantry.");
							glPopMatrix();

							///

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "900 denaries.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/4 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "1000 denaries.");
							glPopMatrix();

							if (enemy_country == 35)
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 175, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "400 denaries.");
								glPopMatrix();
							}
							else
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 175, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "1500 denaries.");
								glPopMatrix();
							}


							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + 3*width/4 , 175, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "500 denaries.");
							glPopMatrix();

							///

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 20");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + width/4 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 24");
							glPopMatrix();

							if (enemy_country == 35)
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 125, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "Power - 17");
								glPopMatrix();
							}
							else
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(10 + 2*width/4 , 125, 0);
								glScalef(0.2,0.2,1.0);
								f->print_stroke_string(stroke_fonts[0], "Power - 28");
								glPopMatrix();
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 + 3*width/4 , 125, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Power - 18");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 75, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Enemy's warriors are chosen. You have ");
							glTranslated(50, 0, 0);
							f->print_stroke_string(stroke_fonts[0], f->string_to_ptrchar(floatToString((countries->country_effects[p] - 1.0f)*100.0f)));
							glTranslated(50, 0, 0);
							if (enemy_country == 35)
								f->print_stroke_string(stroke_fonts[0],"% upon Rome.");
							else
								f->print_stroke_string(stroke_fonts[0],"% upon Seleucids.");
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(10 , 25, 0);
							glScalef(0.2,0.2,1.0);
							f->print_stroke_string(stroke_fonts[0], "Press B for return, N - for going to counting scores for battle.");
							glPopMatrix();

							char heavy_cav[20];
							char inf[20];
							char arta[20];
							char arch[20];
							char eleph[20];

							itoa(algy->enemy_troops["heavyhorseman"], heavy_cav, 10);
							itoa(algy->enemy_troops["infantry"], inf, 10);
							itoa(algy->enemy_troops["artillery"], arta, 10);
							itoa(algy->enemy_troops["archers"], arch, 10);
							itoa(algy->enemy_troops["elephants"], eleph, 10);

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(width/8 , 260, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], arta);
							glPopMatrix();

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(3*width/8 , 260, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], heavy_cav);
							glPopMatrix();

							if (enemy_country == 35)
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(5*width/8 , 260, 0);
								glScalef(0.3,0.3,1.0);
								f->print_stroke_string(stroke_fonts[0], arch);
								glPopMatrix();
							}
							else
							{
								glPushMatrix();
								glColor3f(1.0, 0.0, 0.0);
								glLineWidth(5.0);
								glTranslated(5*width/8 , 260, 0);
								glScalef(0.3,0.3,1.0);
								f->print_stroke_string(stroke_fonts[0], eleph);
								glPopMatrix();
							}

							glPushMatrix();
							glColor3f(1.0, 0.0, 0.0);
							glLineWidth(5.0);
							glTranslated(7*width/8 , 260, 0);
							glScalef(0.3,0.3,1.0);
							f->print_stroke_string(stroke_fonts[0], inf);
							glPopMatrix();
						};
				}
				if (next_pressed)
				{
					pair<string, int> p("enemy_warriors recruited", 7);
					state->states.push_back(p);
					next_pressed = false;
				}
				rand_value = true;
				glutPostRedisplay();
				break;
			};
		case 7:
			{
				next_available = true;
				int your_score, enemy_score;
				srand(time(0));
				if (rand_value)
				{
					your_score = rand() % 6 + 1;
					enemy_score = rand() % 6 + 1;
					countries->set_your_score(your_score);
					countries->set_enemy_score(enemy_score);
					rand_value = false;
				}
				char score_1[20];
				char score_2[20];
				itoa(countries->get_your_score(), score_1, 10);
				itoa(countries->get_enemy_score(), score_2, 10);
				
				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(width/4 , 260, 0);
				glScalef(2.0,2.0,1.0);
				f->print_stroke_string(stroke_fonts[0], score_1);
				glPopMatrix();

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(3*width/4 , 260, 0);
				glScalef(2.0,2.0,1.0);
				f->print_stroke_string(stroke_fonts[0], score_2);
				glPopMatrix();

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 , 125, 0);
				glScalef(0.3,0.3,1.0);
				f->print_stroke_string(stroke_fonts[0], "Your score");
				glPopMatrix();

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 + width/2 , 125, 0);
				glScalef(0.3,0.3,1.0);
				f->print_stroke_string(stroke_fonts[0], "Enemy's score");
				glPopMatrix();

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10, 75, 0);
				glScalef(0.3,0.3,1.0);
				f->print_stroke_string(stroke_fonts[0], "Back - B, result battle - N");
				glPopMatrix();

				if (next_pressed)
				{
					pair<string, int> p("score counted", 8);
					state->states.push_back(p);
					next_pressed = false;
					glutPostRedisplay();
				}

				break;
			};
		case 8:
			{
				next_available = false;
				rand_value = true;

				battle->set_your_score(countries->get_your_score());
				battle->set_enemy_score(countries->get_enemy_score());

				battle->troops = w->troops;
				battle->enemy_troops = algy->enemy_troops;

				float score = battle->count_battle(state->states[state->states.size() - 8].first, state->states[state->states.size() - 6].first);

				glBindTexture(GL_TEXTURE_2D, t->texName_countries[2]);

				glBegin(GL_QUADS);
				glTexCoord2i(0, 0); glVertex2i(0, 0);
				glTexCoord2i(0, 1); glVertex2i(0, height);
				glTexCoord2i(1, 1); glVertex2i(width, height);
				glTexCoord2i(1, 0); glVertex2i(width, 0);
				glEnd();

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(10.0);
				glTranslated(10 , 400, 0);
				glScalef(0.5,0.5,1.0);
				f->print_stroke_string(stroke_fonts[0], "Your score is ");
				glTranslated(50, 0, 0);
				f->print_stroke_string(stroke_fonts[0], f->string_to_ptrchar(floatToString(score)));
				glTranslated(50, 0, 0);
				f->print_stroke_string(stroke_fonts[0], " %");
				glPopMatrix();
				
				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(10.0);
				glTranslated(10 , 200, 0);
				glScalef(1.0,1.0,1.0);

				if (score > 0)
					f->print_stroke_string(stroke_fonts[0], "YOU WIN!");
				else if (score < 0)
					f->print_stroke_string(stroke_fonts[0], "YOU LOSE!");
				else
					f->print_stroke_string(stroke_fonts[0], "NICHYA");
				glPopMatrix();

				glPushMatrix();
				glColor3f(1.0, 0.0, 0.0);
				glLineWidth(5.0);
				glTranslated(10 , 25, 0);
				glScalef(0.2,0.2,1.0);
				f->print_stroke_string(stroke_fonts[0], "Press B for going back");
				glPopMatrix();
				break;
			};
	}
	glutSwapBuffers();
}

void init()
{
	quit_available = next_available = next_pressed = return_available = choose_country_available = begin_enter_money = end_enter_money = 
		choose_barbarians = choose_carthage = choose_egypt = choose_parthia = choose_rome = choose_seleucids = false;
	check_time = spending_money = check_alg = rand_value = true;
	t = new Textures();
	f = new Fonts();
	countries = new Countries();
	w = new Warriors();
	p_w = new Picture_Warriors();
	pict_countries = new Picture_Countries();
	state = new State();
	algy = new Algorithms_EnemyCountry();
	battle = new Battle_Result();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("Ancient battles");
	init();
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	PlaySound(TEXT("../requiem.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	glutMainLoop();
	delete_function();
	return 0;
}


