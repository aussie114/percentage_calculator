import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk, Gdk
from src.widgets import *

def configure():
	window.set_title("Percentage Calculator")
	window.set_resizable(False)

	grid = Gtk.Grid()
	window.add(grid)
	grid.set_margin_top(10)
	grid.set_margin_bottom(10)
	grid.set_margin_start(10)
	grid.set_margin_end(10)
	grid.set_row_spacing(5)
	grid.set_column_spacing(5)
	widgets[13][0].set_halign(Gtk.Align.START)

	for widget in widgets:
		grid.attach(widget[0], widget[1], widget[2], widget[3], widget[4])
