#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Color_Chooser.H>

struct Info
{
    // The widgets
    Fl_Input* instr;
    Fl_Int_Input* inint;

    // Saved values
    char sval[40];
    int  ival;
};

// Callback for the done button
void done_cb(Fl_Widget* w, void* param)
{
    Info* input = reinterpret_cast<Info*>(param);

    // Get the values from the widgets
    strcpy (input->sval, input->instr->value());
    input->ival = atoi(input->inint->value());

    // Print the values
    printf("String value is %s\n", input->sval);
    printf("Integer value is %d\n", input->ival);
    printf("ghh %s\n",input->sval);

}

int main(int argc, char **argv)
{
    Info input;

    // Setup the colours
    Fl::args(argc, argv);
    Fl::get_system_colors();

    // Create the window
    Fl_Window *window = new Fl_Window(200, 150);
    int x = 50, y = 10, w = 100, h = 30;
    input.instr = new Fl_Input(x, y, w, h, "Str");
    input.instr->tooltip("String input");

    y += 35;
    input.inint = new Fl_Int_Input(x, y, w, h, "Int");
    input.inint->tooltip("Integer input");

    y += 35;
    Fl_Button* done = new Fl_Button(x, y, 100, h, "Done");
    done->callback(done_cb, &input);
    window->end();

    window->show(argc, argv);
    return Fl::run();
}
