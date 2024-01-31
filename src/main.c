// main.c
#include "cpu.h"
#include <gtk/gtk.h>

void init_gui() {
    gtk_init(NULL, NULL);
}

void create_window() {
    GtkWidget *window;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "NES Emulator");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
}

int main() {
    init_gui();
    create_window();

    CPU cpu;
    init_cpu(&cpu);

    // Execute a few CPU cycles
    for (int i = 0; i < 10; i++) {
        execute_cpu_cycle(&cpu);
    }

    gtk_main(); // Start GTK main loop

    return 0;
}
