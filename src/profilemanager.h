#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include "common.h"
#include "keychainclass.h"
#include <QDialog>
#include <QJsonObject>

namespace Ui {
class ProfileManager;
}

class QStringListModel;
class ProfileManager : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileManager(QWidget *parent = nullptr);
    ~ProfileManager();

    QJsonObject profiles = {};
    QStringListModel *model;

    bool loadProfile(SaveFormat saveFormat);
    void saveProfile(SaveFormat saveFormat);

    void updateModel();

    void afterShowOneTime();

signals:
    void keyRestored(const QString &profile);

private:
    Ui::ProfileManager *ui;
    bool m_modified = false;
    KeyChainClass keyChain;
    QString otp_secret;

    void resetForm();

    void readKeys();
    void writeKeys();

public:
    void setOTPSecret(const QString &secret);
    QString getOTPSecret() const;
};

#endif // PROFILEMANAGER_H
