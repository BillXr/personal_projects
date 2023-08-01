DROP DATABASE IF EXISTS my_db;
CREATE DATABASE my_db;
USE my_db;
CREATE TABLE DEPT(DEPTNO INT(2) NOT NULL, DNAME VARCHAR(14),LOC VARCHAR(14), PRIMARY KEY(DEPTNO));
CREATE TABLE EMP(EMPNO INT(4) NOT NULL,ENAME VARCHAR(10),JOB VARCHAR(25), MGR INT(4), HIREDATE DATE, SAL FLOAT(7,2),COMM FLOAT(7,2),DEPTNO INT(2),PRIMARY KEY(EMPNO),FOREIGN KEY(DEPTNO) REFERENCES DEPT(DEPTNO));
INSERT INTO DEPT (DEPTNO, DNAME, LOC)
	VALUES (10, 'ACCOUNTING', 'NEW YORK');
INSERT INTO DEPT(DEPTNO, DNAME, LOC)
	VALUES (20, 'RESEARCH', 'DALLAS');
INSERT INTO DEPT(DEPTNO, DNAME, LOC)
	VALUES (30, 'SALES', 'CHICAGO');
INSERT INTO DEPT(DEPTNO, DNAME, LOC)
	VALUES (40, 'OPERATIONS', 'BOSTON');
INSERT INTO EMP
	VALUES (7369,'SMITH','CLERK',7902,'1980/12/17',800,NULL,20);
INSERT INTO EMP
	VALUES (7499,'ALLEN','SALESMAN',7698,'1981/02/20',1600,300,30);
INSERT INTO EMP
	VALUES (7521,'WARD','SALESMAN',7698,'2002/02/01',1250,500,30);
INSERT INTO EMP
	VALUES (7566,'JONES','MANAGER',7839,'1981/12/24',2975,NULL,20);
INSERT INTO EMP
	VALUES (7654,'MARTIN','SALESMAN',7698,'1981/10/28',1250,1400,30);
INSERT INTO EMP
	VALUES (7698,'BLAKE','MANAGER',7839,'2001/05/02',2850,NULL,30);
INSERT INTO EMP
	VALUES (7782,'CLARK','MANAGER',7839,'1981/11/27',2450,NULL,10);
INSERT INTO EMP
	VALUES (7788,'SCOTT','ANALYST',7566,'1987/04/29',3000,NULL,20);
INSERT INTO EMP
	VALUES (7839,'KING','PRESIDENT',NULL,'1987/11/12',5000,NULL,10);
INSERT INTO EMP
	VALUES (7844,'TURNER','SALESMAN',7698,'2007/10/19',1500,0,30);
INSERT INTO EMP
	VALUES (7876,'ADAMS','CLERK',7788,'2003/05/07',1100,NULL,20);
INSERT INTO EMP
	VALUES (7900,'JAMES','CLERK',7698,'2003/12/12',950,NULL,30);
INSERT INTO EMP
	VALUES (7902,'FORD','ANALYST',7566,'2003/12/19',3000,NULL,20);
INSERT INTO EMP
	VALUES (7934,'MILLER','CLERK',7782,'2003/01/19',1300,NULL,10);
INSERT INTO EMP
	VALUES (7999,'BATES','ANALYST',7566,'2004/01/04',1300,NULL,NULL);
