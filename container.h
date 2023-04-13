#ifndef CONTAINER_H
#define CONTAINER_H

#include <QObject>
#include <QDateTime>
#include <QTimeZone>

class Container : public QObject
{
    Q_OBJECT
public:
    Container(QObject *parent = nullptr) { Q_UNUSED(parent); }
    virtual ~Container() {}

    QTime startTime() { return m_startTime; }
    QTime durationTime() { return m_durationTime; }
    QDateTime endDateTime() { return m_endDateTime; }

    void setStartTime(QTime startTime) {
        if (startTime == m_startTime)
            return;
        m_startTime = startTime;
        emit startTimeChanged(startTime);
        setEndDateTime(QDate::currentDate().startOfDay(QTimeZone::systemTimeZone()).addSecs(QTime(0,0,0).secsTo(m_durationTime) + QTime(0,0,0).secsTo(m_startTime)));
    }
    void setDurationTime(QTime durationTime) {
        if (durationTime == m_durationTime)
            return;
        m_durationTime = durationTime;
        emit durationTimeChanged(durationTime);
        setEndDateTime(QDate::currentDate().startOfDay(QTimeZone::systemTimeZone()).addSecs(QTime(0,0,0).secsTo(m_durationTime) + QTime(0,0,0).secsTo(m_startTime)));
    }
    void setEndDateTime(QDateTime endDateTime) {
        if (endDateTime == m_endDateTime)
            return;
        m_endDateTime = endDateTime;
        emit endDateTimeChanged(endDateTime);
    }

signals:
    void startTimeChanged(QTime startTime);
    void durationTimeChanged(QTime durationTime);
    void endDateTimeChanged(QDateTime endDateTime);

private:
    QTime m_startTime = QTime::currentTime();
    QTime m_durationTime = QTime::fromString("8:40", "h:m");
    QDateTime m_endDateTime = QDate::currentDate().startOfDay(QTimeZone::systemTimeZone()).addSecs(QTime(0,0,0).secsTo(m_durationTime) + QTime(0,0,0).secsTo(m_startTime));
};

#endif // CONTAINER_H
