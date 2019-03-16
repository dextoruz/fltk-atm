// helloask.cxx (example2a)

#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <Fl/Fl_Text_Display.H>
// #include <Fl/Fl_Menu_Bar>
#include <FL/Fl_Wizard.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Enumerations.H>
#include <iostream>
#include <string>
#include <fstream>

void model(Fl_Widget *, void *) {
    Fl_Window *head = new Fl_Window(400, 350, "Robot Model: ");
    Fl_Input *input = new Fl_Input(200, 0, 100, 30, "Name: ");
    Fl_Input *input1 = new Fl_Input(200, 40, 100, 30, "Part-Number: ");
    Fl_Input *input2 = new Fl_Input(200, 80, 100, 30, "How much is the    Weight: ");
    Fl_Input *input3 = new Fl_Input(200, 120, 100, 30, "The Cost: ");
    Fl_Input *input4 = new Fl_Input(200, 160, 100, 30, "Brief Description:           ");
    Fl_Button *enter = new Fl_Button(150, 200, 100, 30, "Enter");
    head->show();
  }

int main(){

Fl_Window *win = new Fl_Window(600, 500, "Robot Workshop");
Fl_Box *box = new Fl_Box(0, 10, 600, 100, "Welcome to Robot Workshop!");
box->box(FL_UP_BOX);
box->labelsize(36);
box->labelfont(FL_BOLD + FL_ITALIC);
box->labeltype(FL_SHADOW_LABEL);
Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, 600, 25);
menu->add("Exit/Quit", FL_CTRL + 'v', Quit_CB);
menu->add("Project Manager/Robot Part/Head", FL_CTRL + 'h', head);
menu->add("Project Manager/Robot Part/Torso", FL_CTRL + 't', torso);
menu->add("Project Manager/Robot Part/Arm", FL_CTRL + 'a', arm);
menu->add("Project Manager/Robot Part/Battery", FL_CTRL + 'b', battery);
menu->add("Project Manager/Robot Part/Locomotor", FL_CTRL + 'l', locomotor);
menu->add("Project Manager/Robot Model" ,FL_CTRL + 'w', model);
menu->add("Beloved Customer/Browse Catalog", FL_CTRL + 'z', catalog);
menu->add("Beloved Customer/Part Pictures", FL_CTRL + 'v', pic);
menu->add("Manual", FL_CTRL + 'm', manual_window);

win->show();
return(Fl::run());

}
