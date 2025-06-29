#include <gtk/gtk.h>
#include "main.h"
#include "config.h"
#include "logic.h"

Widgets widgets;

GtkWidget * create(GtkWidget * widget, int x, int y, int w, int h)
{
	gtk_grid_attach(GTK_GRID(widgets.grid), widget, x, y, w, h);
	return widget;
}

void activate(GtkApplication * app, gpointer user_data)
{
	(void)user_data;

	widgets.window = gtk_application_window_new(app);
	widgets.grid =   gtk_grid_new();

	widgets.label_0_0 = create(gtk_label_new("what is "),                                 0, 0, 1, 1);
    widgets.entry_0_X = create(gtk_entry_new(),                                           1, 0, 1, 1);
    widgets.label_0_1 = create(gtk_label_new("%                                    of"),  2, 0, 1, 1);
    widgets.entry_0_Y = create(gtk_entry_new(),                                           3, 0, 1, 1);
    widgets.label_0_2 = create(gtk_label_new(" ?"),                                       4, 0, 1, 1);
    widgets.button_0  = create(gtk_button_new_with_label("Calculate"),                    5, 0, 1, 1);
    widgets.output_0  = create(gtk_entry_new(),                                           6, 0, 1, 1);

    widgets.entry_1_X = create(gtk_entry_new(),                                           1, 1, 1, 1);
    widgets.label_1_0 = create(gtk_label_new("is what percentage of"),                    2, 1, 1, 1);
    widgets.entry_1_Y = create(gtk_entry_new(),                                           3, 1, 1, 1);
    widgets.label_1_1 = create(gtk_label_new(" ?"),                                       4, 1, 1, 1);
    widgets.button_1  = create(gtk_button_new_with_label("Calculate"),                    5, 1, 1, 1);
    widgets.output_1  = create(gtk_entry_new(),                                           6, 1, 1, 1);
    widgets.label_1_2 = create(gtk_label_new("%"),                                        7, 1, 1, 1);

	widgets.label_2_0 = create(gtk_label_new("What is the percentage increase/decrease"), 0, 2, 3, 1);

    widgets.label_3_0 = create(gtk_label_new("from"),                                     0, 3, 1, 1);
    widgets.entry_3_X = create(gtk_entry_new(),                                           1, 3, 1, 1);
    widgets.label_3_1 = create(gtk_label_new("to"),                                       2, 3, 1, 1);
    widgets.entry_3_Y = create(gtk_entry_new(),                                           3, 3, 1, 1);
    widgets.label_3_2 = create(gtk_label_new(" ?"),                                       4, 3, 1, 1);
    widgets.button_3  = create(gtk_button_new_with_label("Calculate"),                    5, 3, 1, 1);
    widgets.output_3  = create(gtk_entry_new(),                                           6, 3, 1, 1);
    widgets.label_3_3 = create(gtk_label_new("%"),                                        7, 3, 1, 1);

    widgets.label_4_0 = create(gtk_label_new("what is "),                                 0, 4, 1, 1);
    widgets.entry_4_X = create(gtk_entry_new(),                                           1, 4, 1, 1);
    widgets.operator_button = create(gtk_button_new_with_label("+"),                      2, 4, 1, 1);
    widgets.entry_4_Y = create(gtk_entry_new(),                                           3, 4, 1, 1);
    widgets.label_4_1 = create(gtk_label_new(" ?"),                                       4, 4, 1, 1);
    widgets.button_4  = create(gtk_button_new_with_label("Calculate"),                    5, 4, 1, 1);
    widgets.output_4  = create(gtk_entry_new(),                                           6, 4, 1, 1);

	GtkEventController * controller = gtk_event_controller_key_new();
	
	config(controller);
	connect_signals(controller);

	gtk_window_present (GTK_WINDOW (widgets.window));
}

int main (int argc, char ** argv)
{
	GtkApplication * program;
	int status;

	program = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect (program, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (program), argc, argv);
	g_object_unref (program);
	return status;
}


