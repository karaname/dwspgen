#include <gtk/gtk.h>
#include "widgets.h"
#include "handlers.h"

struct Containers cont;
struct Controllers cllr;
struct Buttons butt;
GtkWidget *window;

void packing()
{
  gtk_box_pack_start(GTK_BOX(cont.vbox), cont.first_row_grid, FALSE, TRUE, 0);
  gtk_box_pack_end(GTK_BOX(cont.vbox), cont.second_row_grid, FALSE, FALSE, 0);

  gtk_grid_attach(GTK_GRID(cont.first_row_grid), GTK_WIDGET(cllr.pass_entry), 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(cont.first_row_grid), GTK_WIDGET(cont.check_grid), 1, 0, 1, 1);

  gtk_grid_attach(GTK_GRID(cont.check_grid), GTK_WIDGET(cllr.len_spin_button), 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(cont.check_grid), GTK_WIDGET(cllr.symbols_check_button), 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(cont.check_grid), GTK_WIDGET(cllr.digits_check_button), 0, 2, 1, 1);

  gtk_grid_attach(GTK_GRID(cont.second_row_grid), GTK_WIDGET(butt.generate_button), 0, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(cont.second_row_grid), GTK_WIDGET(butt.to_clipboard_button), 1, 0, 1, 1);
  gtk_grid_attach(GTK_GRID(cont.second_row_grid), GTK_WIDGET(butt.clear_clipboard_button), 2, 0, 1, 1);
}

void create_controllers()
{
  cllr.pass_entry = gtk_entry_new();
  gtk_widget_set_valign(GTK_WIDGET(cllr.pass_entry), GTK_ALIGN_CENTER);
  gtk_widget_set_halign(GTK_WIDGET(cllr.pass_entry), GTK_ALIGN_END);
  gtk_widget_set_size_request(GTK_WIDGET(cllr.pass_entry), 180, 35);

  cllr.digits_check_button = gtk_check_button_new_with_label("Digits");
  cllr.symbols_check_button = gtk_check_button_new_with_label("Special symbols");
  cllr.len_spin_button = gtk_spin_button_new_with_range(8, 40, 1);

  butt.generate_button = gtk_button_new_with_label("Generate");
  butt.to_clipboard_button = gtk_button_new_with_label("To clipboard");
  butt.clear_clipboard_button = gtk_button_new_with_label("Clear clipboard");
  gtk_widget_set_tooltip_text(GTK_WIDGET(butt.generate_button), "Generate random password");
  gtk_widget_set_tooltip_text(GTK_WIDGET(butt.to_clipboard_button), "Put the password on the clipboard");
  gtk_widget_set_tooltip_text(GTK_WIDGET(butt.clear_clipboard_button), "Clear clipboard from password");
}

void create_containers()
{
  cont.vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

  cont.first_row_grid = gtk_grid_new();
  gtk_grid_insert_row(GTK_GRID(cont.first_row_grid), 1);
  gtk_grid_insert_column(GTK_GRID(cont.first_row_grid), 2);
  gtk_grid_set_row_homogeneous(GTK_GRID(cont.first_row_grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(cont.first_row_grid), TRUE);

  cont.second_row_grid = gtk_grid_new();
  gtk_grid_insert_row(GTK_GRID(cont.second_row_grid), 1);
  gtk_grid_insert_column(GTK_GRID(cont.second_row_grid), 3);
  gtk_grid_set_row_homogeneous(GTK_GRID(cont.second_row_grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(cont.second_row_grid), TRUE);
  gtk_grid_set_column_spacing(GTK_GRID(cont.second_row_grid), 40);
  gtk_container_set_border_width(GTK_CONTAINER(cont.second_row_grid), 15);

  cont.check_grid = gtk_grid_new();
  gtk_grid_insert_row(GTK_GRID(cont.check_grid), 3);
  gtk_grid_insert_column(GTK_GRID(cont.check_grid), 1);
  gtk_grid_set_row_spacing(GTK_GRID(cont.check_grid), 5);
  gtk_grid_set_row_homogeneous(GTK_GRID(cont.check_grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(cont.check_grid), TRUE);
  gtk_widget_set_valign(GTK_WIDGET(cont.check_grid), GTK_ALIGN_CENTER);
  gtk_widget_set_halign(GTK_WIDGET(cont.check_grid), GTK_ALIGN_CENTER);
  gtk_container_set_border_width(GTK_CONTAINER(cont.check_grid), 10);
}

int main(int argc, char **argv)
{
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "dwsp - Random Password Generator");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  create_containers();
  create_controllers();
  packing();

  gtk_container_add(GTK_CONTAINER(window), cont.vbox);
  gtk_widget_show_all(window);
  g_signal_connect(G_OBJECT(window), "destroy", gtk_main_quit, NULL);
  g_signal_connect(G_OBJECT(butt.generate_button), "clicked", G_CALLBACK(on_generate_button_clicked), NULL);
  g_signal_connect(G_OBJECT(butt.to_clipboard_button), "clicked", G_CALLBACK(on_clipboard_button_clicked), NULL);
  g_signal_connect(G_OBJECT(butt.clear_clipboard_button), "clicked", G_CALLBACK(on_clear_clipboard_button_clicked), NULL);

  gtk_main();

  return 0;
}
