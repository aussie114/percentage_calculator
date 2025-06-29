#ifndef MAIN_H
#define MAIN_H

typedef struct 
{
    GtkWidget * window;
    GtkWidget * grid;

	GtkWidget *  label_0_0;
    GtkWidget *  entry_0_X;
    GtkWidget *  label_0_1;
    GtkWidget *  entry_0_Y;
    GtkWidget *  label_0_2;
    GtkWidget * button_0;
    GtkWidget * output_0;

    GtkWidget *  entry_1_X;
    GtkWidget *  label_1_0;
    GtkWidget *  entry_1_Y;
    GtkWidget *  label_1_1;
    GtkWidget * button_1;
    GtkWidget * output_1;
    GtkWidget *  label_1_2;

	GtkWidget *  label_2_0;

	GtkWidget *  label_3_0;
    GtkWidget *  entry_3_X;
    GtkWidget *  label_3_1;
    GtkWidget *  entry_3_Y;
    GtkWidget *  label_3_2;
    GtkWidget * button_3;
    GtkWidget * output_3;
    GtkWidget *  label_3_3;

	GtkWidget *  label_4_0;
    GtkWidget *  entry_4_X;
    GtkWidget *  operator_button;
    GtkWidget *  entry_4_Y;
    GtkWidget *  label_4_1;
    GtkWidget * button_4;
    GtkWidget * output_4;
} Widgets;

extern Widgets widgets;

#endif
