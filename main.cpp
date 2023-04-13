#include <QApplication>
#include <QMainWindow>
#include <QTimeEdit>
#include <QFormLayout>
#include "container.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow window;
    QWidget widget;

    Container container;

    QTimeEdit startField(container.startTime());
    QTimeEdit durationField(container.durationTime());
    QDateTimeEdit endField(container.endDateTime());

    QObject::connect(&startField, &QTimeEdit::timeChanged, &container, &Container::setStartTime);
    QObject::connect(&durationField, &QTimeEdit::timeChanged, &container, &Container::setDurationTime);
    QObject::connect(&endField, &QTimeEdit::dateTimeChanged, &container, &Container::setEndDateTime);

    QObject::connect(&container, &Container::startTimeChanged, &startField, &QTimeEdit::setTime);
    QObject::connect(&container, &Container::durationTimeChanged, &durationField, &QTimeEdit::setTime);
    QObject::connect(&container, &Container::endDateTimeChanged, &endField, &QTimeEdit::setDateTime);

    QFormLayout formLayout;
    formLayout.addRow("Start", &startField);
    formLayout.addRow("Duration", &durationField);
    formLayout.addRow("End", &endField);

    widget.setLayout(&formLayout);

    window.setCentralWidget(&widget);
    window.resize(250, 200);
    window.show();

    return a.exec();
}
