class Test {
  public static void main (String[] args) {
    Person p1 = new Person("Martin Kozeny");
    System.out.println("Person name is " + p1.getName());

    // now let's change name
    changeName(p1);

    /*
     * OK by now, if Java is passing 'p1' as a reference everything
     * in the method 'changeName' shall be reflected.
     */
    System.out.println("Person name NOW is " + p1.getName());
  }

  static void changeName (Person p) {
    p.setName("Michael Schumacher");

    /*
     * If "p" is a reference, then the instance of "p" will now be changed!
     * Else the instance will be the same and name will be "Michael Schumacher"
     */
    p = new Person("Niki Lauda");
  }
}

class Person {
  String _name;

  public String getName() {
    return this._name;
  }

  public void setName(String name) {
    System.out.println("Setting Person name to " + name);
    this._name = name;
  }

  public Person(String name) {
    this._name = name;
  }
}
