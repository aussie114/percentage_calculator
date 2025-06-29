#include <gtk/gtk.h>
#include "main.h"

void config(GtkEventController * controller)
{
	// Widnow
	gtk_window_set_title        ( GTK_WINDOW (widgets.window), "Window");
	gtk_window_set_resizable    ( GTK_WINDOW (widgets.window), FALSE);

	// grid
	gtk_window_set_child (GTK_WINDOW (widgets.window), widgets.grid);
	gtk_widget_set_margin_top   (widgets.grid, 4);
	gtk_widget_set_margin_end   (widgets.grid, 4);
	gtk_widget_set_margin_bottom(widgets.grid, 4);
	gtk_widget_set_margin_start (widgets.grid, 4);
	gtk_grid_set_column_spacing(GTK_GRID(widgets.grid), 2);
	gtk_grid_set_row_spacing(GTK_GRID(widgets.grid), 2);

	gtk_editable_set_editable(GTK_EDITABLE(widgets.output_0), false);
	gtk_editable_set_editable(GTK_EDITABLE(widgets.output_1), false);
	gtk_editable_set_editable(GTK_EDITABLE(widgets.output_3), false);
	gtk_editable_set_editable(GTK_EDITABLE(widgets.output_4), false);

	gtk_widget_set_halign(widgets.label_2_0, GTK_ALIGN_START);

	gtk_widget_add_controller(widgets.window, controller);

}
