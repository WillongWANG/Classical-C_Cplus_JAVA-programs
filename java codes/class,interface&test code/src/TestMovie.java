import  java.io.*;
import java.lang.reflect.*;

/**
 * Test driver for class <code>Movie</code>.
 *
 * @author  author name
 * @version  1.0.0
 * @see Movie
 */
public class TestMovie  {

	/* Standard output stream */
	private static PrintWriter  stdOut =
		new  PrintWriter(System.out, true);

	/* Standard error stream */
	private static PrintWriter  stdErr =
		new  PrintWriter(System.err, true);

	/**
	 * Displays a message in the standard error stream if the value specified
	 * by parameter <code>condition<code> is <code>false</code>.
	 *
	 * @param message  the error message.
	 * @param condition  the test condition.
	 */
	public static void assertTrue(String message, boolean condition) {

		if (! condition) {
			stdErr.print("** Test failure ");
			stdErr.println(message);

			System.exit(0);
		}
	}

	/**
	 * Displays a message in the standard error stream.
	 *
	 * @param message  the error message.
	 */
	public static void fail(String message) {

		stdErr.print("** Test failure ");
		stdErr.println(message);

		System.exit(0);
	}

	/**
	 * Test driver for class <code>Movie</code>.
	 *
	 * @param args  not used.
	 */
	public static void  main(String[] args)  {

		Movie movie;

		Class classDescriptor = null;

		try {
			classDescriptor  = Class.forName("Movie");
		} catch (ClassNotFoundException cnfe) {
			fail("1: Class Movie not found " +
				"(check the name of the class)");
		}

		assertTrue("2: Class Movie is not abstract",
			Modifier.isAbstract(classDescriptor.getModifiers()));

		// Testing constructor
		Constructor[] constructors = classDescriptor.getConstructors();
		
		assertTrue("3: Movie should contain one public constructor",
			constructors.length == 1);

		Class[] parameterTypes = constructors[0].getParameterTypes();

		assertTrue(
			"4: the number of parameter of the constructor is incorrect",
			parameterTypes.length == 3);
				
		assertTrue("5: the parameters of the constructor are incorrect ",
			parameterTypes[0].getName().equals("java.lang.String") &&
			parameterTypes[1].getName().equals("[Ljava.lang.String;") &&
			parameterTypes[2].getName().equals("java.lang.String"));

		Method[] methods = classDescriptor.getDeclaredMethods();

		assertTrue("6: Movie should contain 4 methods",
			methods.length == 4);

		try {
			Method method = classDescriptor.getMethod("getTitle", null);
			Class returnType = method.getReturnType();

			assertTrue("7: the return type of method getTitle is incorrect",
				returnType.getName().equals("java.lang.String"));

		} catch (NoSuchMethodException nsme) {
			fail("8: Method getTitle not found " +
				"(check the name of the method)");
		}

		try {
			Method method = classDescriptor.getMethod("getActors", null);
			Class returnType = method.getReturnType();

			assertTrue("9: the return type of method getActors is incorrect",
				returnType.getName().equals("[Ljava.lang.String;"));

		} catch (NoSuchMethodException nsme) {
			fail("10: Method getActors not found " +
				"(check the name of the method)");
		}

		try {
			Method method = classDescriptor.getMethod("getDirector", null);
			Class returnType = method.getReturnType();

			assertTrue("11: the return type of method getDirector is incorrect",
				returnType.getName().equals("java.lang.String"));

		} catch (NoSuchMethodException nsme) {
			fail("12: Method getDirector not found " +
				"(check the name of the method)");
		}

		try {
			Method method = classDescriptor.getMethod("toString", null);
			Class returnType = method.getReturnType();

			assertTrue("13: the return type of method toString is incorrect",
				returnType.getName().equals("java.lang.String"));

		} catch (NoSuchMethodException nsme) {
			fail("14: Method toString not found " +
				"(check the name of the method)");
		}


		stdOut.println("done");

	}
}
