#pragma once
#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H
#include <QDataStream>
#include <QString>
#include <QVector>

/**
 * @brief A robot teljes állapotleírása le egy adott időpillanatban.
 *
 * A kommunikáció során ilyen objektumokat küldünk át a robot és a kliens között.
 * A robottól érkezve az aktuális állapotot képviseli, míg az ellenkező irányba küldve
 *  parancsként a kívánt állapotot írja le.
 *
 * A history ilyen objektumok sorozata.
 */

/**
 * @brief @see Itt egy STATE viselkedési mintát véltem felfedezni. A state minta lehetővé teszi egy objektum számára, hogy megváloztassa a működését, ha a belső állapota változik.
 * @see A robotnak mindig van egy aktuális állapota, amit felhasználunk. Egyszerűen gombokkal tudjuk változtatni az állapotát. Ezt az aktuális állapotot, az állapot le tudja cserélni.
 * @see Láthatjuk a RobotProxy állapotokat.
 */
class RobotState : public QObject
{
    Q_OBJECT


public:
    /**
     * @brief A robot állapota
     */
    enum class Status
    {
        /** Alapállapot. A robot tartja az aktuális gyorsulást. */
        Default = 0,
        /** Reset. Parancsként használjuk. */
        Reset = 1,
        /** Stop parancs. Ez az állapot akkor is érvényes marad, ha megállt a robot. */
        Stopping = 2,
        /** Gyorsítási parancs a robotnak. A gyorsítás mértékét a robot
         * átveszi a RobotState::a tulajdonságból. */
        Accelerate = 3,
        /** Hiba jelzésére szolgáló állapot. Akkor lép ide a robot, ha valamilyen probléma lép fel. Például túlfeszültség. */
        Error = 4,
        /** Öntesztelés állapota */
        SelfTest = 5
    };

    /**
     * @brief Konstruktor
     */
    RobotState();

    /**
     * @brief Konstruktor adott értékekkel.
     * @param status    Robot állapot
     * @param timestamp Időbélyeg
     * @param x Pozíció
     * @param v Sebesség
     * @param a Gyorsulás
     * @param light Robot lámpájának állapota
     * @param error Robot öntesztelése esetén felmerülő hibája
     */

    RobotState(Status status, qint64 timestamp, float x, float v, float a,QVector<int>g, qint8 light, QString error);

    ~RobotState() = default;

    // A NOTIFY signalokat nem implementáljuk, mert nincs rájuk szükség.

    /** Állapot (vagy parancs) */
    Q_PROPERTY(Status status READ status WRITE setStatus MEMBER _status NOTIFY statusChanged)
    Status status() const { return _status; }
    void setStatus(const Status status) { _status = status; }

    /** Időbélyeg (ms) */
    Q_PROPERTY(float timestamp READ timestamp WRITE setTimestamp MEMBER _timestamp NOTIFY timestampChanged)
    qint64 timestamp() const { return _timestamp; }
    void setTimestamp(const qint64 timestamp) { _timestamp = timestamp; }

    /** Pozíció (méter) */
    Q_PROPERTY(float x READ x WRITE setX MEMBER _x NOTIFY xChanged)
    float x() const { return _x; }
    void setX(float x) { _x = x; }

    /** Sebesség (m/s) */
    Q_PROPERTY(float v READ v WRITE setV MEMBER _v NOTIFY vChanged)
    float v() const { return _v; }
    void setV(float v) { _v = v; }

    /** Gyorsulás (m/s2) */
    Q_PROPERTY(float a READ a WRITE setA MEMBER _a NOTIFY aChanged)
    float a() const { return _a; }
    void setA(float a) { _a = a; }

    /** Gyroszkóp  */
    Q_PROPERTY(QVector<int> g READ g WRITE setG MEMBER _g NOTIFY aChanged)
    QVector<int> g() const {return _g;}
    void setG(QVector<int>  g) {_g=g;}

    /** A robot lámpájának állapota. */
    Q_PROPERTY(bool light READ light WRITE setLight MEMBER _light NOTIFY lightChanged)
    float light() const { return _light; }
    void setLight(float light) { _light = light; }

    /** A robot hibájának kiiratására. */
    Q_PROPERTY(QString error READ error WRITE setError MEMBER _error NOTIFY errorChanged)
    QString error() const { return _error; }
    void setError(QString error) { _error = error; }

    /** Az aktuális állapot QStringként. */
    // In QML, it will be accessible as model.statusName
    Q_PROPERTY(QString statusName READ getStatusName NOTIFY statusChanged)

    /** Sorosítja az objektumot a megadott streambe. */
    void WriteTo(QDataStream& stream) const;

    /** Beolvassa az objektumot a streamből. */
    void ReadFrom(QDataStream& stream);

    /** Másolat készítés. */
    // Erre azért van szükség, mert a QObject-ek másolására speciális szabályok vonatkoznak.
    void CopyFrom(const RobotState& other);

    /** Olvaható formában visszaadja az állapotot. */
    QString getStatusName() const;

signals:
    // Ezeket a signalokat most nem használjuk */
    void statusChanged();
    void timestampChanged();
    void xChanged();
    void vChanged();
    void aChanged();
    void lightChanged();
    void errorChanged();

private:
    Status _status;
    qint64 _timestamp;
    float _x;   /** Pozíció (m) */
    float _v;   /** Sebesség (m/s) */
    float _a;   /** Gyorsulás (m/s2) */

    QVector<int>  _g ;
    qint8 _light;
    QString _error;

    /** Az állapotok és szöveges verziójuk közti megfeleltetés.
     * A getStatusName() használja. */
    static std::map<int,QString> statusNames;

    /** Beállítja a statusNames értékeit. A konstruktor hívja. */
    void initStatusNames();
};

/** Beburkolja a RobotState.WriteTo metódust. */
QDataStream &operator<<(QDataStream &, const RobotState &);

/** Beburkolja a RobotState.ReadFrom metódust. */
QDataStream &operator>>(QDataStream &, RobotState &);

#endif // ROBOTSTATE_H
