#include <gtk/gtk.h>

// compiles
// gcc $(pkg-config --cflags gtk4) -o name-gtk name-gtk.c $(pkg-config --libs gtk4)

static void activate(GtkApplication *app, gpointer user){
    GtkWidget *window;

    // Creating new window
    window = gtk_application_window_new(app);
    // Setting titles
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    // Seetting the default size for window
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    // Adding tool bars into the window
    GtkWidget *toolbar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 100);
    GtkWindow *windows_get = GTK_WINDOW(window);

    // use container 
    // containers contain boxes
    // use css to have hover properties that will have a drop down menu

    gtk_window_set_child(windows_get, toolbar);
    gtk_window_present(windows_get);
}

// Starting application of the GTK application
int main (int argc, char **argv){
    GtkApplication *app;

    int status;

    // Setting a new application
    app = gtk_application_new("testing.test.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    // Run window
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;

}
