#ifndef MRZLEFTMENUBARWIDGET_H
#define MRZLEFTMENUBARWIDGET_H

#include <QWidget>

class QPushButton;
class MrzPushButton;

class MrzLeftMenuBarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzLeftMenuBarWidget(QWidget *parent = nullptr);

signals:

private:
    void initUI();

private:
    // QPushButton *m_pHomeBtn;
    // QPushButton *m_pCalendarBtn;
    // QPushButton *m_pMeetingBtn;
    // QPushButton *m_pTaskBtn;
    // QPushButton *m_pTeamBtn;

    MrzPushButton *m_pHomeBtn;
};

#endif // MRZLEFTMENUBARWIDGET_H
