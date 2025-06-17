#src/logic.py
import gi
gi.require_version("Gtk", "4.0")
from gi.repository import Gtk, Gdk

def connect_signals(window, widgets):

    indexes = [
        [ 1,  3,  5,  6, 0],
        [ 7,  9, 11, 12, 1],
        [15, 17, 19, 20, 2],
        [22, 24, 26, 27, 3]
    ]

    for i in range(4):
        widgets[ indexes[i][0] ][0].connect_object("activate", on_calculate_button_pressed, [ widgets[ indexes[i][0] ][0], widgets[ indexes[i][1] ][0], widgets[ indexes[i][3] ][0], widgets[23][0], indexes[i][4] ])
        widgets[ indexes[i][1] ][0].connect_object("activate", on_calculate_button_pressed, [ widgets[ indexes[i][0] ][0], widgets[ indexes[i][1] ][0], widgets[ indexes[i][3] ][0], widgets[23][0], indexes[i][4] ])
        widgets[ indexes[i][2] ][0].connect_object("clicked",  on_calculate_button_pressed, [ widgets[ indexes[i][0] ][0], widgets[ indexes[i][1] ][0], widgets[ indexes[i][3] ][0], widgets[23][0], indexes[i][4] ])

    widgets[23][0].connect_object("clicked",  on_operator_button_pressed, widgets)

    controller = Gtk.EventControllerKey.new()
    controller.connect("key-pressed", on_key_press)
    window.add_controller(controller)

def on_key_press(controller, keyval, keycode, state):
    if keyval == Gdk.KEY_Escape:
        Gtk.Application.get_default().quit()
        return True
    return False

def on_calculate_button_pressed(args):
    x_input  = args[0].get_text()
    y_input  = args[1].get_text()
    output   = args[2]
    operator = args[3].get_label()
    mode     = args[4]

    x = 0
    y = 0
    try:
        x = float(x_input)
        y = float(y_input)
    except:
        output.set_text("%g" % 0)
        return

    if   mode == 0:
        output.set_text("%g" %     (    y * (x / 100)    ) )
    elif mode == 1:
        output.set_text("%g" %     (    x / (y / 100)    ) )
    elif mode == 2:
        output.set_text("%g" %     ( (y - x) / (x / 100) ) )
    elif mode == 3:
        if   operator == "+":
            output.set_text("%g" % (  x + (x * (y/100))  ) )
        elif operator == "-":
            output.set_text("%g" % (  x - (x * (y/100))  ) )
    else:
        return

def on_operator_button_pressed(widgets):
    if widgets[23][0].get_label() == "+":
        widgets[23][0].set_label("-")
    else:
        widgets[23][0].set_label("+")

    on_calculate_button_pressed( [widgets[22][0], widgets[24][0], widgets[27][0], widgets[23][0], 3] )




