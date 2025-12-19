
#include <QApplication>
#include "AccueilForm.h"


#include <qt5/QtWidgets/qwidget.h>

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here
    
    
    AccueilForm catalog;
    catalog.show();

    return app.exec();
}
