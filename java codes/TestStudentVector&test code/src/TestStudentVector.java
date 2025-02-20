import java.io.*;
import java.util.*;

/**
 * Test the class <code>StudentVector</code>
 *
 * @author Alfonso Rodr�guez
 * @version 1.0.0
 * @see Student
 * @see StudentVector
 */
public class  TestStudentVector  {

	/* Standard output stream */
	private static PrintWriter  stdOut =
		new  PrintWriter(System.out, true);

	/* Standard error stream */
	private static PrintWriter  stdErr =
		new  PrintWriter(System.err, true);

	/* Variables that contains the test objects */
	private Student  first;
	private Student  second;
	private Student  third;
	private Student  fourth;
	private Student  fifth;
	private Student  firstVectorTwo;
	private Student  secondVectorTwo;
	private Student  thirdVectorTwo;
	private Student  fourthVectorTwo;
	private Student  fifthVectorTwo;
	private Vector  empty;
	private Vector  vector;
	private Vector  vectorTwo;

	/**
	 * Tests methods of class {@link StudentVector}
	 *
	 * @param args  not used
	 */
	public static void main (String args[]) {

		TestStudentVector tester = new TestStudentVector();

		if (tester.testMakeVector() & tester.testMakeVectorFromArray() &
			tester.testHasStudent() &
			tester.testCountGradeGreaterOrEqual() &
			tester.testGetMinGrade() & tester.testGetGradeAverage() &
			tester.testRemoveGradeLess() & tester.testDisplayAll()) {
			stdOut.println("All tests passed");
		}

	}

	/**
	 * Displays a message in the standard error stream if the value specified
	 * by parameter <code>condition<code> is <code>false</code>.
	 *
	 * @param message  the error message.
	 * @param condition  the test condition.
	 * @return the value of <code>condition</code>
	 */
	public static boolean assertTrue(String message, boolean condition) {

		if (!condition) {
			stdErr.print("** Test failure ");
			stdErr.println(message);

			return false;
		} else {

			return true;
		}

	}

	/** Assign the initial value to the test variables */
	private void setUp() {

		first = new Student(10, "First", 100);
		second = new Student(20, "Second", 90);
		third = new Student(30, "Third", 80);
		fourth = new Student(40, "Fourth", 90);

		firstVectorTwo = new Student(10, "First", 50);
		secondVectorTwo = new Student(20, "Second", 90);
		thirdVectorTwo = new Student(30, "Third", 80);
		fourthVectorTwo = new Student(40, "Fourth", 80);
		fifthVectorTwo = new Student(50, "Fifth", 90);

		empty = new Vector();

		vector = new Vector();
		vector.add(first);
		vector.add(second);
		vector.add(third);
		vector.add(fourth);

		vectorTwo = new Vector();
		vectorTwo.add(firstVectorTwo);
		vectorTwo.add(secondVectorTwo);
		vectorTwo.add(thirdVectorTwo);
		vectorTwo.add(fourthVectorTwo);
		vectorTwo.add(fifthVectorTwo);
	}

	/**
	 * Test the method <code>makeVector3</code>
	 *
	 * @return <code>true</code> if all test passed; otherwise returns
	 *         <code>false</code>.
	 */
	public boolean testMakeVector() {

		setUp();

		boolean test = true;

		Vector result =
			StudentVector.makeVector(first, second, third);

		test = test && assertTrue("1, testing method makeVector",
			result instanceof Vector);
		test = test && assertTrue("2, testing method makeVector",
			result.size() == 3);
		test = test && assertTrue("3, testing method makeVector",
			result.get(0) == first);
		test = test && assertTrue("4, testing method makeVector",
			result.get(1) == second);
		test = test && assertTrue("5, testing method makeVector",
			result.get(2) == third);

		return test;
	}

	/**
	 * Test the method <code>makeVectorFromArray</code>
	 *
	 * @return <code>true</code> if all test passed; otherwise returns
	 *         <code>false</code>.
	 */
	public boolean testMakeVectorFromArray() {

		setUp();

		boolean test = true;

		Vector empty = StudentVector.makeVectorFromArray(new Student[0]);

		test = test && assertTrue("1, testing method makeVectorFromArray",
			empty instanceof Vector);
		test = test && assertTrue("2, testing method makeVectorFromArray",
			empty.size() == 0);

		Student arr[] = {first, second, third};
		Vector result = StudentVector.makeVectorFromArray(arr);

		test = test && assertTrue("3, testing method makeVectorFromArray",
			result instanceof Vector);
		test = test && assertTrue("4, testing method makeVectorFromArray",
			result.size() == 3);
		test = test && assertTrue("5, testing method makeVectorFromArray",
			result.get(0) == first);
		test = test && assertTrue("6, testing method makeVectorFromArray",
			result.get(1) == second);
		test = test && assertTrue("7, testing method makeVectorFromArray",
			result.get(2) == third);

		return test;
	}

	/**
	 * Test the method <code>hasStudent</code>.
	 *
	 * @return <code>true</code> if all test passed; otherwise returns
	 *         <code>false</code>.
	 */
	public boolean testHasStudent() {

		setUp();

		boolean test = true;

		test = test && assertTrue("1, testing method hasStudent",
			!StudentVector.hasStudent(empty, first.getId()));
		test = test && assertTrue("2, testing method hasStudent",
			StudentVector.hasStudent(vector, first.getId()));
		test = test && assertTrue("3, testing method hasStudent",
			StudentVector.hasStudent(vector, second.getId()));
		test = test && assertTrue("4, testing method hasStudent",
			StudentVector.hasStudent(vector, third.getId()));
		test = test && assertTrue("5, testing method hasStudent",
			StudentVector.hasStudent(vector, fourth.getId()));
		test = test && assertTrue("6, testing method hasStudent",
			! StudentVector.hasStudent(vector, 555));

		return test;
	}

	/**
	 * Test the method <code>countGradeGreaterOrEqual</code>.
	 *
	 * @return <code>true</code> if all test passed; otherwise returns
	 *         <code>false</code>.
	 */
	public boolean testCountGradeGreaterOrEqual() {

		setUp();

		boolean test = true;

		test = test && assertTrue("1, testing method countGradeGreaterOrEqual",
			StudentVector.countGradeGreaterOrEqual(vector, 50) == 4);

		test = test && assertTrue("2, testing method countGradeGreaterOrEqual",
			StudentVector.countGradeGreaterOrEqual(vector, 100) == 1);

		return test;
	}

	/**
	 * Test the method <code>getMinGrade</code>.
	 *
	 * @return <code>true</code> if test passed; otherwise returns
	 *         <code>false</code>.
	 */
	public boolean testGetMinGrade() {

		setUp();

		boolean test = true;
		
		test = test && assertTrue("1, testing method getMinGrade",
			StudentVector.getMinGrade(vector) == 80);
			
		test = test && assertTrue("2, testing method getMinGrade",
			StudentVector.getMinGrade(vectorTwo) == 50);
			
		return test;

	}

	/**
	 * Test the method <code>getGradeAverage</code>.
	 *
	 * @return <code>true</code> if test passed; otherwise returns
	 *         <code>false</code>.
	 */
	public boolean testGetGradeAverage() {

		setUp();

		return assertTrue("1, testing method getGradeAverage",
			StudentVector.getGradeAverage(vector) ==
				(first.getGrade() + second.getGrade() + third.getGrade() +
				fourth.getGrade()) / 4.0);
	}

	/**
	 * Test the method <code>removeGradeLess</code>.
	 *
	 * @return <code>true</code> if all test passed; otherwise returns
	 *         <code>false</code>.
	 */
	public boolean testRemoveGradeLess() {

		setUp();

		boolean test = true;

		StudentVector.removeGradeLess(empty, 100);
		test = test && assertTrue("1, testing method removeGradeLess",
			empty.size() == 0);

		StudentVector.removeGradeLess(vector, 90);
		test = test && assertTrue("2, testing method removeGradeLess",
			vector.size() == 3);
		test = test && assertTrue("3, testing method removeGradeLess",
			vector.get(0) == first);
		test = test && assertTrue("4, testing method removeGradeLess",
			vector.get(1) == second);
		test = test && assertTrue("5, testing method removeGradeLess",
			vector.get(2) == fourth);

		StudentVector.removeGradeLess(vectorTwo, 90);
		test = test && assertTrue("6, testing method removeGradeLess",
			vectorTwo.size() == 2);
		test = test && assertTrue("7, testing method removeGradeLess",
			vectorTwo.get(0) == secondVectorTwo);
		test = test && assertTrue("8, testing method removeGradeLess",
			vectorTwo.get(1) == fifthVectorTwo);

		return test;
	}

	/**
	 * Test the method <code>displayAll</code>.
	 *
	 * @return <code>true</code> if test passed; otherwise returns
	 *         <code>false</code>.
	 */
	public boolean testDisplayAll() {

		setUp();

		return assertTrue("1, testing method displayAll",
			StudentVector.displayAll(vector).equals(
				first.toString() + "\n" + second.toString() + "\n" +
				third.toString() + "\n" + fourth.toString()));
	}
}