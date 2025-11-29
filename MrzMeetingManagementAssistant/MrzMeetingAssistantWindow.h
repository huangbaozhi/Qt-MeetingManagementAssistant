#ifndef MRZMEETINGASSISTANTWINDOW_H
#define MRZMEETINGASSISTANTWINDOW_H

#include <QWidget>

class MrzTitleBarWidget;
class MrzLeftMenuBarWidget;
class MrzCentralContentStackedWidget;

class MrzMeetingAssistantWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MrzMeetingAssistantWindow(QWidget *parent = nullptr);

signals:

private:
    void initUI();

private:
    MrzTitleBarWidget *m_pMrzTitleBarWidget;
    MrzLeftMenuBarWidget *m_pMrzLeftMenuBarWidget;
    MrzCentralContentStackedWidget *m_pMrzCentralContentStackedWidget;
};

#endif // MRZMEETINGASSISTANTWINDOW_H
