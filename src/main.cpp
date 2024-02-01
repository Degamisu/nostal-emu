// main.cpp
#include "cpu.h"
#include <QApplication>
#include <QMainWindow>

void init_gui(QApplication &app) {
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("NES Emulator");
    mainWindow.setGeometry(100, 100, 800, 600);
    mainWindow.show();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    init_gui(app);

    CPU cpu;
    cpu.init();

    // Execute a few CPU cycles
    for (int i = 0; i < 10; i++) {
        cpu.executeCycle();
    }

    return app.exec();
}
