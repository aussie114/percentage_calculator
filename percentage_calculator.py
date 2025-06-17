#!/usr/bin/env python3
#percentage_calculator.py
import gi
gi.require_version("Gtk", "4.0")
from gi.repository import Gtk, Gdk
from src.config import *
from src.logic import *

def on_activate(program):
    window = Gtk.ApplicationWindow(application=program)
    grid = Gtk.Grid()

    widgets = [
        [Gtk.Label(label="what is "),                                 0, 0, 1, 1], #00
        [Gtk.Entry(),                                                 1, 0, 1, 1], #01
        [Gtk.Label(label="%                                    of"),  2, 0, 1, 1], #02
        [Gtk.Entry(),                                                 3, 0, 1, 1], #03
        [Gtk.Label(label=" ?"),                                       4, 0, 1, 1], #04
        [Gtk.Button(label="Calculate"),                               5, 0, 1, 1], #05
        [Gtk.Entry(),                                                 6, 0, 1, 1], #06

        [Gtk.Entry(),                                                 1, 1, 1, 1], #07
        [Gtk.Label(label="is what percentage of"),                    2, 1, 1, 1], #08
        [Gtk.Entry(),                                                 3, 1, 1, 1], #09
        [Gtk.Label(label=" ?"),                                       4, 1, 1, 1], #10
        [Gtk.Button(label="Calculate"),                               5, 1, 1, 1], #11
        [Gtk.Entry(),                                                 6, 1, 1, 1], #12
        
        [Gtk.Label(label="What is the percentage increase/decrease"), 0, 2, 3, 1],#13

        [Gtk.Label(label="from"),                                     0, 3, 1, 1], #14
        [Gtk.Entry(),                                                 1, 3, 1, 1], #15
        [Gtk.Label(label="to"),                                       2, 3, 1, 1], #16
        [Gtk.Entry(),                                                 3, 3, 1, 1], #17
        [Gtk.Label(label=" ?"),                                       4, 3, 1, 1], #18
        [Gtk.Button(label="Calculate"),                               5, 3, 1, 1], #19
        [Gtk.Entry(),                                                 6, 3, 1, 1], #20

        [Gtk.Label(label="what is "),                                 0, 4, 1, 1], #21
        [Gtk.Entry(),                                                 1, 4, 1, 1], #22
        [Gtk.Button(label="+"),                                       2, 4, 1, 1], #23
        [Gtk.Entry(),                                                 3, 4, 1, 1], #24
        [Gtk.Label(label=" ?"),                                       4, 4, 1, 1], #25
        [Gtk.Button(label="Calculate"),                               5, 4, 1, 1], #26
        [Gtk.Entry(),                                                 6, 4, 1, 1], #27
    ]

    configure(window, grid, widgets)
    connect_signals(window, widgets)
    window.present()

program = Gtk.Application()
program.connect("activate", on_activate)
program.run(None)
