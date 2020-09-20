CC=g++

ezsql:
	$(CC) -lmariadb -o ezSql ezSqlTest.cpp ezSql.cpp

clean:
	rm ezSql
