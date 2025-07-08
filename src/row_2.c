#include <gtk/gtk.h>
#include "grid.h"
#include "create.h"

void create_row_2()
{
	GtkWidget * label = create(gtk_label_new("What is the percentage increase/decrease"), 0, 2, 3, 1);
	gtk_widget_set_halign(label, GTK_ALIGN_START);
}
