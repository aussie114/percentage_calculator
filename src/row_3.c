#include <gtk/gtk.h>
#include "grid.h"
#include "create.h"

static GtkWidget * entry_X;
static GtkWidget * entry_Y;
static GtkWidget * button;
static GtkWidget * output;

static void on_button_pressed(GtkWidget * caller, gpointer data)
{
	(void)caller;
	(void)data;
	gdouble x = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(entry_X)), NULL );
	gdouble y = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(entry_Y)), NULL );
	gchar * output_text = g_strdup_printf("%g", (y - x) / (x / 100) );
	gtk_editable_set_text(GTK_EDITABLE(output), output_text);
	g_free(output_text);
}

void create_row_3()
{
              create(gtk_label_new("from"),                  0, 3, 1, 1);
    entry_X = create(gtk_entry_new(),                        1, 3, 1, 1);
              create(gtk_label_new("to"),                    2, 3, 1, 1);
    entry_Y = create(gtk_entry_new(),                        3, 3, 1, 1);
              create(gtk_label_new(" ?"),                    4, 3, 1, 1);
    button  = create(gtk_button_new_with_label("Calculate"), 5, 3, 1, 1);
    output  = create(gtk_entry_new(),                        6, 3, 1, 1);
              create(gtk_label_new("%"),                     7, 3, 1, 1);

	g_signal_connect(button,  "clicked",  G_CALLBACK(on_button_pressed), NULL); 
	g_signal_connect(entry_X, "activate", G_CALLBACK(on_button_pressed), NULL);
	g_signal_connect(entry_Y, "activate", G_CALLBACK(on_button_pressed), NULL);
}
