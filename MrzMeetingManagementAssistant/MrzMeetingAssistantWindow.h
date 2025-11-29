#ifndef MRZMEETINGASSISTANTWINDOW_H
#define MRZMEETINGASSISTANTWINDOW_H

#include <QWidget>

class MrzMeetingAssistantWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MrzMeetingAssistantWindow(QWidget *parent = nullptr);

signals:

private:
    void initUI();
};

#endif // MRZMEETINGASSISTANTWINDOW_H
