



import java.util.*;

/**
 * This class contains methods to process vectors of {@link Student} objects.
 *
 * @author  author name
 * @version  1.0.0
 * @see  Student
 * @see  Vector
 */
public class  StudentVector  {

	/**
	 * Returns a vector with three elements.
	 *
	 * @param first  a <code>Student</code> object.
	 * @param second  a <code>Student</code> object.
	 * @param third  a <code>Student</code> object.
	 * @return a vector with the objects <code>first</code>,
	 *           <code>second</code>, and <code>third</code>
	 */
	public static Vector makeVector(Student  first, Student  second,
	                                Student  third)  {

		Vector vector=new Vector();
		vector.add(first);
		vector.add(second);
		vector.add(third);
		return vector;
	}

	/**
	 * Returns a vector with the same elements of the specified array
	 * arranged in the same order.
	 *
	 * @param array  an array with <code>Student</code> objects .
	 * @return a vector with the same elements of the specified array
	 *         arranged in the same order
	 */
	public static Vector makeVectorFromArray(Student[] array) {

		Vector vector=new Vector();
		for(int i=0;i< array.length;i++)
		{vector.add(array[i]);}

		return vector;
	}

	/**
	 * Returns <code>true</code> if the specified vector contains a
	 * student whose ID matches the specified ID.
	 *
	 * @param vector  a vector of <code>Student</code> objects.
	 * @param id  a student ID.
	 * @return  <code>true</code> if the specified vector contains a
	 *          student whose ID matches the specified ID;
	 *          <code>false</code> otherwise.
	 */
	public static boolean hasStudent(Vector  vector, int  id)  {

		Iterator i= vector.iterator();
	for(;i.hasNext();)
	{
		Student s=(Student) i.next();
		if(s.getId()==id) return true;

	}
		return false;
	}

	/**
	 * Returns the number of students in the specified vector whose
	 * grade is greater than or equal to the specified grade.
	 *
	 * @param vector  a vector of <code>Student</code> objects.
	 * @param grade  a grade.
	 * @return  the number of students in the specified vector whose
	 *          grade is greater than or equal to the specified grade.
	 */
	public static int countGradeGreaterOrEqual(Vector vector, int grade)  {

int m=0;
		for(Iterator i= vector.iterator();i.hasNext();)
		{
			Student s=(Student) i.next();
			if(s.getGrade()>=grade) m++;

		}

		return m;
	}

	/**
	 * Returns the smallest grade of the students in the specified vector.
	 * <p>
	 * This method assumes that the vector is not empty.
	 *
	 * @param vector  a vector of <code>Student</code> objects.
	 * @return  the smallest grade of the students in the specified vector.
	 */
	public static int getMinGrade(Vector vector)  {

		Iterator i= vector.iterator();
		Student s=(Student) i.next();
		int m=s.getGrade();
		for(;i.hasNext();)
		{
			Student s1=(Student) i.next();
			int m1=s1.getGrade();
			if(m>=m1) m=m1;

		}

		return m;


	}

	/**
	 * Returns the average grade of the students in the specified vector.
	 *
	 * @param vector  a vector of <code>Student</code> objects.
	 * @return  the average grade of the students in the specified vector.
	 */
	public static double getGradeAverage(Vector vector)  {

		double m=0;
		for(Iterator i= vector.iterator();i.hasNext();)
		{
			Student s=(Student) i.next();
			m=m+s.getGrade();

		}

		return m/vector.size();


	}

	/**
	 * Removes all students in the specified vector whose grade
	 * is less than the specified grade.
	 *
	 * @param vector  a vector of <code>Student</code> objects.
	 * @param grade  a grade.
	 */
	public static void removeGradeLess(Vector  vector, int  grade)  {


		for(Iterator i= vector.iterator();i.hasNext();)
		{
			Student s=(Student) i.next();
			if(s.getGrade()<grade) i.remove();//错：vector.remove(s);

		}


	}

	/**
	 * Returns the string representation of the objects in the specified
	 * vector.
	 * <p>
	 * A new line character ( \n ) should separate the string
	 * representations of the objects. For example:
	 * </p>
	 * <pre>
	 * Student[328,Galileo Galilei,80]\nStudent[123,Albert Einstein,100]
	 * </pre>
	 * <p>
	 * Note that the string does <i>not</i> end with a new line character ( \n ).
	 * </p>
	 *
	 * @param vector  a vector of <code>Student</code> objects.
	 * @return  the string representation of the objects in the specified
	 *          vector.
	 */
	public static String displayAll(Vector  vector)  {

String ss= "";
Iterator i= vector.iterator();
i.hasNext();boolean b=true;
		while(b)
		{
			Student s=(Student) i.next();
			ss=ss+s.toString();
			if(b=i.hasNext()) ss=ss+"\n";

		}
return ss;

}
}