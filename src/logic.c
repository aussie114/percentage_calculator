#include <gtk/gtk.h>
#include "main.h"

gboolean on_key_pressed(GtkEventControllerKey * controller, guint keyval, guint keycode, GdkModifierType state, gpointer user_data)
{
    (void)controller;
    (void)keycode;
    (void)state;
	if (keyval == GDK_KEY_Escape) 
	{
		gtk_window_destroy(GTK_WINDOW(user_data));
		return TRUE;
	}
		return FALSE;
}

void calculate(GtkWidget * caller, gpointer data)
{
	(void)caller;
	int mode = GPOINTER_TO_INT(data);
	gchar * output_text;

	if      (mode == 0)
	{
		gdouble x = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(widgets.entry_0_X)), NULL );
		gdouble y = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(widgets.entry_0_Y)), NULL );
		output_text = g_strdup_printf("%g", y * (x / 100) );
		gtk_editable_set_text(GTK_EDITABLE(widgets.output_0), output_text);
	}
	else if (mode == 1)
	{
		gdouble x = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(widgets.entry_1_X)), NULL );
		gdouble y = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(widgets.entry_1_Y)), NULL );
		output_text = g_strdup_printf("%g", x / (y / 100) );
		gtk_editable_set_text(GTK_EDITABLE(widgets.output_1), output_text);
	}
	else if (mode == 3)
	{
		gdouble x = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(widgets.entry_3_X)), NULL );
		gdouble y = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(widgets.entry_3_Y)), NULL );
		output_text = g_strdup_printf("%g", (y - x) / (x / 100) );
		gtk_editable_set_text(GTK_EDITABLE(widgets.output_3), output_text);
	}
	else if (mode == 4)
	{
		if (gtk_button_get_label(GTK_BUTTON(widgets.operator_button))[0] == '+' )
		{
			gdouble x = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(widgets.entry_4_X)), NULL );
			gdouble y = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(widgets.entry_4_Y)), NULL );
			output_text = g_strdup_printf("%g", x + (x * (y / 100)) );
			gtk_editable_set_text(GTK_EDITABLE(widgets.output_4), output_text);
		}
		else
		{
			gdouble x = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(widgets.entry_4_X)), NULL );
			gdouble y = g_ascii_strtod( gtk_editable_get_text(GTK_EDITABLE(widgets.entry_4_Y)), NULL );
			output_text = g_strdup_printf("%g", x - (x * (y / 100)) );
			gtk_editable_set_text(GTK_EDITABLE(widgets.output_4), output_text);
		}
	}
	else
	{
		return;
	}
	g_free(output_text);
}

void on_operator_button_pressed(GtkWidget * caller, gpointer data)
{
	(void)caller;
	(void)data;
	if (gtk_button_get_label(GTK_BUTTON(widgets.operator_button))[0] == '+' )
	{
		gtk_button_set_label(GTK_BUTTON(widgets.operator_button), "-");
	}
	else
	{
		gtk_button_set_label(GTK_BUTTON(widgets.operator_button), "+");
	}
}

void connect_signals(GtkEventController * controller)
{
	g_signal_connect(widgets.button_0,    "clicked", G_CALLBACK(calculate), GINT_TO_POINTER(0));
	g_signal_connect( widgets.entry_0_X, "activate", G_CALLBACK(calculate), GINT_TO_POINTER(0));
	g_signal_connect( widgets.entry_0_Y, "activate", G_CALLBACK(calculate), GINT_TO_POINTER(0));

	g_signal_connect(widgets.button_1,    "clicked", G_CALLBACK(calculate), GINT_TO_POINTER(1));
	g_signal_connect( widgets.entry_1_X, "activate", G_CALLBACK(calculate), GINT_TO_POINTER(1));
	g_signal_connect( widgets.entry_1_Y, "activate", G_CALLBACK(calculate), GINT_TO_POINTER(1));

	g_signal_connect(widgets.button_3,    "clicked", G_CALLBACK(calculate), GINT_TO_POINTER(3));
	g_signal_connect( widgets.entry_3_X, "activate", G_CALLBACK(calculate), GINT_TO_POINTER(3));
	g_signal_connect( widgets.entry_3_Y, "activate", G_CALLBACK(calculate), GINT_TO_POINTER(3));

	g_signal_connect(widgets.button_4,    "clicked", G_CALLBACK(calculate), GINT_TO_POINTER(4));
	g_signal_connect( widgets.entry_4_X, "activate", G_CALLBACK(calculate), GINT_TO_POINTER(4));
	g_signal_connect( widgets.entry_4_Y, "activate", G_CALLBACK(calculate), GINT_TO_POINTER(4));

	g_signal_connect(widgets.operator_button, "clicked", G_CALLBACK(on_operator_button_pressed), NULL);
	g_signal_connect(widgets.operator_button, "clicked", G_CALLBACK(calculate), GINT_TO_POINTER(4));

	g_signal_connect(controller, "key-pressed", G_CALLBACK(on_key_pressed), widgets.window);
}


