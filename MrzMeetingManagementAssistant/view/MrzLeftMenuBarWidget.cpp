#include "MrzLeftMenuBarWidget.h"
#include "components/MrzPushButton.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QToolButton>

/**
 * @brief MrzLeftMenuBarWidget
 * @param parent
 * @details 菜单栏
 */

MrzLeftMenuBarWidget::MrzLeftMenuBarWidget(QWidget *parent)
    : QWidget{parent}
{
    initUI();
}

void MrzLeftMenuBarWidget::initUI()
{
    QHBoxLayout *pMainLyt = new QHBoxLayout(this);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setFixedWidth(280);
    pMainWgt->setFixedHeight(840);
    pMainWgt->setStyleSheet("QWidget{left: 0px;border-radius: 0px 0px 0px 0px;background-color: rgba(255,255,255,1);border: 1px solid rgba(226,232,240,1);}");

    QHBoxLayout *phMenuLyt = new QHBoxLayout(pMainWgt);
    phMenuLyt->setContentsMargins(0, 0, 0, 0);
    QVBoxLayout *pMenuLyt = new QVBoxLayout;
    pMenuLyt->setContentsMargins(0, 0, 0, 0);



    // QPushButton *m_pHomeBtn;
    // QPushButton *m_pCalendarBtn;
    // QPushButton *m_pMeetingBtn;
    // QPushButton *m_pTaskBtn;
    // QPushButton *m_pTeamBtn;

    // m_pHomeBtn = new QPushButton(this);
    // m_pHomeBtn->setText("首页");
    // m_pCalendarBtn = new QPushButton(this);
    // m_pCalendarBtn->setText("日历");
    // m_pMeetingBtn = new QPushButton(this);
    // m_pMeetingBtn->setText("会议");
    // m_pTaskBtn = new QPushButton(this);
    // m_pTaskBtn->setText("任务");
    // m_pTeamBtn = new QPushButton(this);
    // m_pTeamBtn->setText("团队");

    m_pHomeBtn = new MrzPushButton(this);
    m_pHomeBtn->setButtonText("首页");
    m_pHomeBtn->setStyleSheet("QWidget{border-radius: 8px;background-color: rgba(115,116,255,1); border: 0px;}");
    pMenuLyt->addWidget(m_pHomeBtn);

    // 自定义三态颜色
    //m_pHomeBtn->setNormalColor(QColor(115, 116, 255, 255));   // 正常状态
    //m_pHomeBtn->setPressedColor(QColor(75, 76, 215, 255));    // 按下状态

    // 自定义三态图标（可选）
    m_pHomeBtn->setNormalIcon(":/images/home.png");
    m_pHomeBtn->setPressedIcon(":/images/create_meeting.png");

    phMenuLyt->addSpacing(24);
    phMenuLyt->addLayout(pMenuLyt);
    phMenuLyt->addSpacing(24);

    pMainLyt->addWidget(pMainWgt);
}
