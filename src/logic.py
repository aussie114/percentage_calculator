import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk, Gdk
from src.widgets import *

def connect_signals():
	widgets[ 1][0].connect("activate", on_calculate_button_0_pressed)
	widgets[ 3][0].connect("activate", on_calculate_button_0_pressed)
	widgets[ 5][0].connect("clicked",  on_calculate_button_0_pressed)

	widgets[ 7][0].connect("activate", on_calculate_button_1_pressed)
	widgets[ 9][0].connect("activate", on_calculate_button_1_pressed)
	widgets[11][0].connect("clicked",  on_calculate_button_1_pressed)

	widgets[15][0].connect("activate", on_calculate_button_2_pressed)
	widgets[17][0].connect("activate", on_calculate_button_2_pressed)
	widgets[19][0].connect("clicked",  on_calculate_button_2_pressed)

	widgets[22][0].connect("activate", on_calculate_button_3_pressed)
	widgets[24][0].connect("activate", on_calculate_button_3_pressed)
	widgets[26][0].connect("clicked",  on_calculate_button_3_pressed)

	widgets[23][0].connect("clicked",  on_operator_button_pressed)

	window.connect("destroy", Gtk.main_quit)
	window.connect("key-press-event", on_key_press)

def on_key_press(widget, event):
	if event.keyval == Gdk.KEY_Escape:
		Gtk.main_quit()
		return True
	return False

def on_calculate_button_0_pressed(caller=None):
	z = 0
	try:
		x = float(widgets[1][0].get_text())
		y = float(widgets[3][0].get_text())
		z = y * (x / 100)
	except:
		z = 0
	
	widgets[6][0].set_text("%g" % z)

def on_calculate_button_1_pressed(caller=None):
	z = 0
	try:
		x = float(widgets[7][0].get_text())
		y = float(widgets[9][0].get_text())
		z = x / (y / 100)
	except:
		z = 0
	
	widgets[12][0].set_text("%g" % z)

def on_calculate_button_2_pressed(caller=None):
	z = 0
	try:
		x = float(widgets[15][0].get_text())
		y = float(widgets[17][0].get_text())
		z = (y - x) / (x / 100)
	except:
		z = 0
	
	widgets[20][0].set_text("%g" % z)

def on_calculate_button_3_pressed(caller=None):
	z = 0
	try:
		x = float(widgets[22][0].get_text())
		y = float(widgets[24][0].get_text())
		if widgets[23][0].get_label() == "+":
			z = x + (x * (y/100))
		else:
			z = x - (x * (y/100))
	except:
		z = 0
	widgets[27][0].set_text("%g" % z)

def on_operator_button_pressed(caller=None):
	if widgets[23][0].get_label() == "+":
		widgets[23][0].set_label("-")
	else:
		widgets[23][0].set_label("+")
	on_calculate_button_3_pressed()
