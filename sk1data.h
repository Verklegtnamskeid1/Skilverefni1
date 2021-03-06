#ifndef SK1DATA_H
#define SK1DATA_H


class sk1Data
{
public:

    sk1Data();

    void add_person(QString name, int gender, int year_born,
                    int year_death);
    void add_person(int id, QString name, int gender, int year_born,
                    int year_death);
    QVector<person> query(int search = GET_ALL, QString searchstring = QString(""),
                          int sort_by = SORT_BY_ID, int sort = SORT_ASCENDING);

    void remove_person(int id);
    void insertlist(QVector<QStringList> list);



private:
    bool lock;
    int latestid;
    QVector<person> entries;

    /* Hjálparföll fyrir sort */
    friend bool sortname(person a, person b);
    friend bool sortgender(person a, person b);
    friend bool sortyearborn(person a, person b);
    friend bool sortyeardeath(person a, person b);
    friend bool sortid(person a, person b);


};



#endif // SK1DATA_H
