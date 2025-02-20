public abstract class Movie {
     private String title;
     private String[] actors;
     private String director;

    public Movie(String initialTitle,
          String[] initialActors,
          String initialDirector)
    {title=initialTitle;actors=initialActors;director=initialDirector;}
    public String getTitle(){return title;}
    public String[] getActors(){return actors;};
    public String getDirector(){return director;};
    public String toString(){return title;};

}
