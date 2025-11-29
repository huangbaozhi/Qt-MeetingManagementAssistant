#include "MrzMeetingAssistantWindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

MrzMeetingAssistantWindow::MrzMeetingAssistantWindow(QWidget *parent)
    : QWidget{parent}
{
    this->setMinimumSize(1440, 900);
    initUI();
}

void MrzMeetingAssistantWindow::initUI()
{
    //QWidget *pMainWgt = new QWidget(this);
    QVBoxLayout *pMainLyt = new QVBoxLayout(this);

    // 标题栏
    QHBoxLayout *pTitleLyt = new QHBoxLayout;
    QWidget *pTitleBarWgt = new QWidget(this);
    QHBoxLayout *pTitleBarLyt = new QHBoxLayout(pTitleBarWgt);

    QLabel *pTitleLbl = new QLabel(this);
    pTitleLbl->setText("会议管理助手");

    QPushButton *pSearchBtn = new QPushButton(this);
    pSearchBtn->setFixedSize(32, 32);
    pSearchBtn->setStyleSheet("QPushButton{image: url(:/images/search.png);background-color:rgba(0,0,0,0);}");

    QPushButton *pMessageBtn = new QPushButton(this);
    pMessageBtn->setFixedSize(32, 32);
    pMessageBtn->setStyleSheet("QPushButton{image: url(:/images/message.png);background-color:rgba(0,0,0,0);}");

    QPushButton *pSetBtn = new QPushButton(this);
    pSetBtn->setFixedSize(32, 32);
    pSetBtn->setStyleSheet("QPushButton{image: url(:/images/set.png);background-color:rgba(0,0,0,0);}");

    QLabel *pProfilePicLbl = new QLabel(this);
    pProfilePicLbl->setFixedSize(32, 32);


    QLabel *pAccountLbl = new QLabel(this);
    //pAccountLbl->setFixedSize(70, 24);
    pAccountLbl->setText("John Doe");

    pTitleBarLyt->addSpacing(32);
    pTitleBarLyt->addWidget(pTitleLbl);
    pTitleBarLyt->addStretch();
    pTitleBarLyt->addWidget(pSearchBtn);
    pTitleBarLyt->addSpacing(24);
    pTitleBarLyt->addWidget(pMessageBtn);
    pTitleBarLyt->addSpacing(24);
    pTitleBarLyt->addWidget(pSetBtn);
    pTitleBarLyt->addSpacing(24);
    pTitleBarLyt->addWidget(pProfilePicLbl);
    pTitleBarLyt->addSpacing(10);
    pTitleBarLyt->addWidget(pAccountLbl);
    pTitleBarLyt->addSpacing(32);

    pTitleLyt->addWidget(pTitleBarWgt);
    pMainLyt->addLayout(pTitleLyt);


    // 左侧栏

    // 中间拦

    // 右侧栏

}
