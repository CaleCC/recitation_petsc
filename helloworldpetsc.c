#include <petscsys.h>
/*PETSc include file*/

int main(int argc, char** argv)
{

	PetscMPIInt rank;
  PetscInt myint = -1;
/* Petsc primitive data types: PetscInt, PetscScalar,PetscReal
  - better to use instead of built-in C types
  - more protable
  - easy to switch between real/complex scalars
  - easy to switch between 32/64-bit numbers
  */
	PetscErrorCode ierr;


	PetscInitialize(&argc, &argv, (char*) 0, 0);
  //Setup static data and services
  //Setup MPI if it is not already


	ierr = MPI_Comm_rank(PETSC_COMM_WORLD, &rank);
  //Determines the rank of the calling process in the communicator
  /*two kind of communicators:
      PETSC_COMM_SELF  contains just a single process ; sequential objects
      PETSC_COMM_WORLD contains all processes; parallel objects

  */
  CHKERRQ(ierr);
  /*
  - C has no support for C++ exceptions
  - every routine return integer error code (PetscErrorCode type)
    - PetscErrorCode err;
      err = SomePetscRoutine(); CHKERRQ(err);

  */
	ierr = PetscPrintf(PETSC_COMM_SELF, "    Hello from %d\n", rank); CHKERRQ(ierr);
  /*Prints to standard out, only from the first processor in the communicator.

  */

	ierr = PetscSynchronizedPrintf(PETSC_COMM_WORLD, "Synchronized Hello from %d\n", rank); CHKERRQ(ierr);
  /*Prints synchronized output from several processors. Output of the first processor is followed by that of the second, etc*/

	ierr = PetscSynchronizedFlush(PETSC_COMM_WORLD,PETSC_STDOUT); CHKERRQ(ierr);
  /*Flushes to the screen output from all processors involved in previous PetscSynchronizedPrintf() calls.*/

	ierr = PetscPrintf(PETSC_COMM_WORLD, "\nHello from ZERO\n\n"); CHKERRQ(ierr);

	ierr = PetscOptionsGetInt(PETSC_NULL, "-myint", &myint, PETSC_NULL); CHKERRQ(ierr);
  /*Gets the integer value for a particular option in the database.*/

	ierr = PetscPrintf(PETSC_COMM_WORLD, "myint = %d\n", myint); CHKERRQ(ierr);

	PetscFinalize();
	return 0;
}
