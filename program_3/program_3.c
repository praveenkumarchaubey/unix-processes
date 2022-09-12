/* Create two executables ("PGM1", "PGM2") from two different C source code files: PGM1.c and PGM2.c.
 * These programs should behave as follows:
 * a) The program "PGM1" should have 4 different versions to do the following:
 * 1. Call fork() and Call exec("PGM2") after fork in the child process 
 * 2. Call exec("PGM2") before fork()
 * 3. Call exec("PGM2") after fork() without checking for return value
 * 4. Call exec("PGM2") after fork() in the parent process
 *
 * b) It does not matter what program PGM2 does, it can have any set of statements
 */
