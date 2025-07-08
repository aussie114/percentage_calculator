#include "main.h"
#include <gtk/gtk.h>
#include "window.h"
#include "grid.h"
#include "row_0.h"
#include "row_1.h"
#include "row_2.h"
#include "row_3.h"
#include "row_4.h"

void activate(GtkApplication * app, gpointer user_data)
{
	(void)user_data;

	create_window(app);
	create_grid();

	create_row_0();
	create_row_1();
	create_row_2();
	create_row_3();
	create_row_4();

	gtk_window_present (GTK_WINDOW (window));
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


