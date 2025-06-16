#!/usr/bin/env python3
import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk, Gdk
from src.widgets import *
from src.config import *
from src.logic import *

def main():
	configure()
	connect_signals()

	window.show_all()
	Gtk.main()

main()
