#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qdom.h"
#include "qtextedit.h"
#include "tabmanager.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void setTextEditProperties(QTextEdit *textEdit);


private slots:
    void on_actionCut_triggered();
    void on_actionExit_triggered();
    void on_actionCopy_triggered();
    void on_actionPast_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionOpen_triggered();
    void on_actionAbout_Qt_triggered();

    void quitApp();
    void createNewTab();
    void closeTab(int index);
    void handleFormatTheFileRequest();
    bool eventFilter(QObject *obj, QEvent *event);
    void handleFormatTheFileRequest(const QString &fileName, QTextEdit *textEdit);

private:
    Ui::MainWindow *ui;
    TabManager *tabManager; // Manages the tabs
    TextEditManager *textEditManager; // Manages the text edit properties
    QTextEdit *currentTextEdit; // Declare a member variable to keep track of the current QTextEdit

    void initializeCloseButton();
    void connectTextEditActions(QTextEdit *textEdit);
    QString formatXml(const QString &xmlContent);
    void colorizeXml(QTextEdit *textEdit);
    void formatNode(const QDomNode &node, QTextStream &stream, int indentationLevel, bool isTopLevel);
    void colorizeNode(const QDomNode &node, QTextCursor &cursor, QTextCharFormat &tagFormat, const QVector<QColor> &colors, int &colorIndex, int level);
};
#endif // MAINWINDOW_H
