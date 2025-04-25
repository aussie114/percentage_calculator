#include <gtk/gtk.h>
#include "gtk_helper_functions.h"

#define MIDDLE_TEXT "What is the percentage increase/decrease"
#define PERCENT_OF "\%                              of"

// ------------------------------------------------------------------------------------ function declarations
static void activate (GtkApplication* app, gpointer data);
void calculate_percentage(gpointer data, int x_entry, int y_entry, int z_entry);
static void on_button_0_pressed(GtkWidget * caller, gpointer data);
static void on_button_1_pressed(GtkWidget * caller, gpointer data);
static void on_button_2_pressed(GtkWidget * caller, gpointer data);
static void on_button_3_pressed(GtkWidget * caller, gpointer data);
static void on_operator_button_pressed(GtkWidget * caller, gpointer data);
static gboolean on_key_pressed(GtkEventControllerKey * controller, guint keyval, guint keycode, GdkModifierType modifiers, gpointer user_data);

// ----------------------------------------------------------------------------------------------------- Main
int main (int argc, char **argv)
{
	GtkWidget * widgets[32];

	GtkApplication *app;
	int status;

	app = gtk_application_new ("org.gtk.percentage_calculator", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect (app, "activate", G_CALLBACK (activate), widgets);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

	return status;
}
// -------------------------------------------------------------------------------------------------- Builder

static void activate (GtkApplication* app, gpointer data)
{
	GtkWidget **widgets = (GtkWidget **)data;

    // Create master window
    widgets[0 ] = ghf_create_window(app, "Percentage Calculator", 894, 152, FALSE);

	// Set up input handling
	GtkEventController * controller = gtk_event_controller_key_new();
	g_signal_connect(controller, "key-pressed", G_CALLBACK(on_key_pressed), widgets[0]);
	gtk_widget_add_controller(widgets[0], controller);

	// Create grid
	widgets[1 ] = ghf_create_grid(2, 2);
	ghf_widget_set_margin_all(widgets[1], 5);
	gtk_window_set_child(GTK_WINDOW(widgets[0]), widgets[1]);

	// Builder
	widgets[2 ] = ghf_create_widget(gtk_label_new("What is"),                widgets[1], 0, 0, 1, 1);
	widgets[3 ] = ghf_create_widget(gtk_entry_new(),                         widgets[1], 1, 0, 1, 1);
	widgets[4 ] = ghf_create_widget(gtk_label_new(PERCENT_OF),               widgets[1], 2, 0, 1, 1);
	widgets[5 ] = ghf_create_widget(gtk_entry_new(),                         widgets[1], 3, 0, 1, 1);
	widgets[6 ] = ghf_create_widget(gtk_label_new("?          "),            widgets[1], 4, 0, 1, 1);
	widgets[7 ] = ghf_create_widget(gtk_button_new_with_label("Calculate"),  widgets[1], 5, 0, 1, 1);
	widgets[8 ] = ghf_create_widget(gtk_entry_new(),                         widgets[1], 6, 0, 1, 1);

	widgets[9 ] = ghf_create_widget(gtk_entry_new(),                         widgets[1], 1, 1, 1, 1);
	widgets[10] = ghf_create_widget(gtk_label_new("is what percentage of"), widgets[1], 2, 1, 1, 1);
	widgets[11] = ghf_create_widget(gtk_entry_new(),                        widgets[1], 3, 1, 1, 1);
	widgets[12] = ghf_create_widget(gtk_label_new("?         "),            widgets[1], 4, 1, 1, 1);
	widgets[13] = ghf_create_widget(gtk_button_new_with_label("Calculate"), widgets[1], 5, 1, 1, 1);
	widgets[14] = ghf_create_widget(gtk_entry_new(),                        widgets[1], 6, 1, 1, 1);
	widgets[15] = ghf_create_widget(gtk_label_new("%"),                     widgets[1], 7, 1, 1, 1);

	widgets[16] = ghf_create_widget(gtk_label_new(MIDDLE_TEXT),             widgets[1], 0, 2, 3, 1);
	gtk_widget_set_halign(widgets[16], GTK_ALIGN_START);

	widgets[17] = ghf_create_widget(gtk_label_new("from"),                  widgets[1], 0, 3, 1, 1);
	widgets[18] = ghf_create_widget(gtk_entry_new(),                        widgets[1], 1, 3, 1, 1);
	widgets[19] = ghf_create_widget(gtk_label_new("to"),                    widgets[1], 2, 3, 1, 1);
	widgets[20] = ghf_create_widget(gtk_entry_new(),                        widgets[1], 3, 3, 1, 1);
	widgets[21] = ghf_create_widget(gtk_label_new("?          "),           widgets[1], 4, 3, 1, 1);
	widgets[22] = ghf_create_widget(gtk_button_new_with_label("Calculate"), widgets[1], 5, 3, 1, 1);
	widgets[23] = ghf_create_widget(gtk_entry_new(),                        widgets[1], 6, 3, 1, 1);
	widgets[24] = ghf_create_widget(gtk_label_new("%"),                     widgets[1], 7, 3, 1, 1);

	widgets[25] = ghf_create_widget(gtk_label_new("What is"),               widgets[1], 0, 4, 1, 1);
	widgets[26] = ghf_create_widget(gtk_entry_new(),                        widgets[1], 1, 4, 1, 1);
	widgets[27] = ghf_create_widget(gtk_button_new_with_label("+"),         widgets[1], 2, 4, 1, 1);
	widgets[28] = ghf_create_widget(gtk_entry_new(),                        widgets[1], 3, 4, 1, 1);
	widgets[29] = ghf_create_widget(gtk_label_new("%          "),           widgets[1], 4, 4, 1, 1);
	widgets[30] = ghf_create_widget(gtk_button_new_with_label("Calculate"), widgets[1], 5, 4, 1, 1);
	widgets[31] = ghf_create_widget(gtk_entry_new(),                        widgets[1], 6, 4, 1, 1);

	// Connect signals
	g_signal_connect(widgets[ 3], "activate", G_CALLBACK(on_button_0_pressed), widgets);
	g_signal_connect(widgets[ 5], "activate", G_CALLBACK(on_button_0_pressed), widgets);
	g_signal_connect(widgets[ 7], "clicked" , G_CALLBACK(on_button_0_pressed), widgets);

	g_signal_connect(widgets[ 9], "activate", G_CALLBACK(on_button_1_pressed), widgets);
	g_signal_connect(widgets[11], "activate", G_CALLBACK(on_button_1_pressed), widgets);
	g_signal_connect(widgets[13], "clicked" , G_CALLBACK(on_button_1_pressed), widgets);

	g_signal_connect(widgets[18], "activate", G_CALLBACK(on_button_2_pressed), widgets);
	g_signal_connect(widgets[20], "activate", G_CALLBACK(on_button_2_pressed), widgets);
	g_signal_connect(widgets[22], "clicked" , G_CALLBACK(on_button_2_pressed), widgets);

	g_signal_connect(widgets[26], "activate", G_CALLBACK(on_button_3_pressed), widgets);
	g_signal_connect(widgets[28], "activate", G_CALLBACK(on_button_3_pressed), widgets);
	g_signal_connect(widgets[30], "clicked" , G_CALLBACK(on_button_3_pressed), widgets);

	g_signal_connect(widgets[27], "clicked" , G_CALLBACK(on_operator_button_pressed), widgets);

	gtk_window_present (         GTK_WINDOW(widgets[0]));
}

// ---------------------------------------------------------------------------------------------------- Logic
static void on_button_0_pressed(GtkWidget * caller, gpointer data)
{
	calculate_percentage(data, 3, 5, 8);
}

static void on_button_1_pressed(GtkWidget * caller, gpointer data)
{
	calculate_percentage(data, 9, 11, 14);
}

static void on_button_2_pressed(GtkWidget * caller, gpointer data)
{
	calculate_percentage(data, 18, 20, 23);
}

static void on_button_3_pressed(GtkWidget * caller, gpointer data)
{
	calculate_percentage(data, 26, 28, 31);
}

static void on_operator_button_pressed(GtkWidget * caller, gpointer data)
{
	GtkWidget ** widgets = (GtkWidget **)data;
	if (gtk_button_get_label( GTK_BUTTON(widgets[27]))[0] == '+' )
	{
		gtk_button_set_label( GTK_BUTTON(widgets[27]), "-" );
	}
	else
	{
		gtk_button_set_label( GTK_BUTTON(widgets[27]), "+" );
	}
}


void calculate_percentage(gpointer data, int x_entry, int y_entry, int z_entry)
{
	GtkWidget **widgets = (GtkWidget **)data;


	double x = g_strtod( gtk_entry_buffer_get_text( gtk_entry_get_buffer( GTK_ENTRY(widgets[x_entry]) ) ), NULL );
	double y = g_strtod( gtk_entry_buffer_get_text( gtk_entry_get_buffer( GTK_ENTRY(widgets[y_entry]) ) ), NULL );

	double z;

	switch (z_entry)
	{
		case 8:
			z = y * (x / 100.0);
			break;
		case 14:
			z = x / (y / 100.0);
			break;
		case 23:
			z = (y - x) / (x / 100);
			break;
		case 31:
			if (gtk_button_get_label( GTK_BUTTON(widgets[27]))[0] == '+' )
			{
				z = x + (x * (y/100));
			}
			else
			{
				z = x - (x * (y/100));
			}
			break;
	}

	char * output = g_strdup_printf("%g", z);
	GtkEntryBuffer * z_output = gtk_entry_get_buffer(GTK_ENTRY(widgets[z_entry]));
	gtk_entry_buffer_set_text(z_output, output, -1);

	g_free(output);

}

// ------------------------------------------------------------------------------------------- Input handling
static gboolean on_key_pressed(GtkEventControllerKey * controller, guint keyval, guint keycode, GdkModifierType modifiers, gpointer user_data)
{
    if (keyval == GDK_KEY_Escape) 
	{
        GtkWindow * window = GTK_WINDOW(user_data);
        gtk_window_close(window);
        return TRUE;
    }
    return FALSE;
}

