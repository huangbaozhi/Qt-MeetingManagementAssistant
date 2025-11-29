#ifndef MRZTOPTITLEBARWIDGET_H
#define MRZTOPTITLEBARWIDGET_H

#include <QWidget>

class QLabel;
class QPushButton;

class MrzTitleBarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MrzTitleBarWidget(QWidget *parent = nullptr);

signals:

private:
    void initUI();

private:
    QLabel      *m_pTitleLbl;
    QPushButton *m_pSearchBtn;
    QPushButton *m_pMessageBtn;
    QPushButton *m_pSetBtn;
    QLabel      *m_pProfilePicLbl;
    QLabel      *m_pAccountLbl;
};

#endif // MRZTOPTITLEBARWIDGET_H
