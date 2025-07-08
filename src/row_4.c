#include <gtk/gtk.h>
#include "grid.h"
#include "create.h"

static GtkWidget * entry_X;
static GtkWidget * operator_button;
static GtkWidget * entry_Y;
static GtkWidget * button;
static GtkWidget * output;

void on_operator_button_pressed(GtkWidget * caller, gpointer data)
{
	(void)caller;
	(void)data;
	if (gtk_button_get_label(GTK_BUTTON(operator_button))[0] == '+' )
	{
		gtk_button_set_label(GTK_BUTTON(operator_button), "-");
	}
	else
	{
		gtk_button_set_label(GTK_BUTTON(operator_button), "+");
	}
}

static void on_button_pressed(GtkWidget * caller, gpointer data)
{
	(void)caller;
	(void)data;
	gdouble x = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(entry_X)), NULL );
	gdouble y = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(entry_Y)), NULL );
	gchar * output_text;
	if (gtk_button_get_label(GTK_BUTTON(operator_button))[0] == '+' )
	{
		output_text = g_strdup_printf("%g", x + (x * (y / 100)) );
	}
	else
	{
		output_text = g_strdup_printf("%g", x - (x * (y / 100)) );
	}
	gtk_editable_set_text(GTK_EDITABLE(output), output_text);
	g_free(output_text);
}

void create_row_4()
{
                      create(gtk_label_new("what is "),              0, 4, 1, 1);
    entry_X         = create(gtk_entry_new(),                        1, 4, 1, 1);
    operator_button = create(gtk_button_new_with_label("+"),         2, 4, 1, 1);
    entry_Y         = create(gtk_entry_new(),                        3, 4, 1, 1);
                      create(gtk_label_new(" ?"),                    4, 4, 1, 1);
    button          = create(gtk_button_new_with_label("Calculate"), 5, 4, 1, 1);
    output          = create(gtk_entry_new(),                        6, 4, 1, 1);

	g_signal_connect(button,  "clicked",  G_CALLBACK(on_button_pressed), NULL); 
	g_signal_connect(entry_X, "activate", G_CALLBACK(on_button_pressed), NULL);
	g_signal_connect(entry_Y, "activate", G_CALLBACK(on_button_pressed), NULL);
	g_signal_connect(operator_button, "clicked", G_CALLBACK(on_operator_button_pressed), NULL);
	g_signal_connect(operator_button, "clicked", G_CALLBACK(on_button_pressed), NULL);
}
