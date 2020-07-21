#include <gtk/gtk.h>
#include "widgets.h"

void generate(char *s, int len)
{
  int index;
  char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  srand(time(NULL));

  for (index = 0; index < len; index++) {
    s[index] = alpha[rand() % (sizeof(alpha) - 1)];
  }
  s[index] = '\0';
}

void on_generate_button_clicked(GtkWidget *generate_button)
{
  int value;
  char pass_buffer[50];

  value = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cllr.len_spin_button));
  generate(pass_buffer, value);
  gtk_entry_set_text(GTK_ENTRY(cllr.pass_entry), pass_buffer);
}

void on_clipboard_button_clicked(GtkWidget *to_clipboard_button)
{
  GtkClipboard *clipboard;
  const char *text = gtk_entry_get_text(GTK_ENTRY(cllr.pass_entry));
  clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
  gtk_clipboard_set_text(clipboard, text, -1);
}

void on_clear_clipboard_button_clicked(GtkWidget *clear_clipboard_button)
{
  GtkClipboard *clipboard;
  clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
  gtk_clipboard_clear(GTK_CLIPBOARD(clipboard));
}
