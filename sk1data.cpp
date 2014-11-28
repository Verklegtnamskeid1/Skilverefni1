#include "main.h"
#include "sk1data.h"


sk1Data::sk1Data()
 {
     lock = false;
     latestid = 0;
 }

QVector<person> sk1Data::query(int search, QString searchstring, int sort_by, int sort)
{
    QVector<person> buffer;
    int compare = 0;

    /* Veljum viðeigandi færslur */
    if (search == GET_ALL) buffer = entries;
    else if (search == GET_BY_NAME)
    {
        foreach(person item, entries)
        {
            if (item.name.contains(searchstring, Qt::CaseInsensitive))
            {
                buffer.push_back(item);
            }
        }

    }
    else {
        int searchnumber = searchstring.toInt();

        foreach(person item, entries)
        {
            switch(search)
            {
                case(GET_BY_ID):
                    compare = item.id;
                    break;
                case(GET_BY_GENDER):
                    compare = item.gender;
                    break;
                case(GET_BY_YEARBORN):
                    compare = item.year_born;
                    break;
                case(GET_BY_YEARDEATH):
                    compare = item.year_death;
                    break;
            }
            if (compare == searchnumber)
                buffer.push_back(item);
         }
    }

    /* Hér þarf að vera sort */


    /* Snúum vektornum við ef beðið er um DESCENDING */
    if (sort != SORT_ASCENDING)
    {
        int size = buffer.count();
        QVector<person> buffer2;

        for (int a = (size -1); a >= 0; a--)
        {
            buffer2.push_back(buffer[a]);
        }

    }

    return buffer;

}



void sk1Data::add_person(QString name, int gender, int year_born, int year_death)
{
    while (lock) {} /* Uhh, threading safe, algjörlega tilgangslaust so far! */
    lock = true;
    person input = person(latestid++, name, gender, year_born, year_death);
    entries.push_back(input);
    lock = false;
}
