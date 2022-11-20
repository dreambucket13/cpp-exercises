#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age {

  class space_age {      
    
    private:

        long int age;
        double earthYears;
    
    public:             

      space_age(long int seconds){
        age = seconds;
        earthYears = (double) seconds / 31557600;
      }

      long int seconds() const {
          return age;
      } 

      double on_earth() const {
        return earthYears;
      }

      double on_mercury() const {
          return earthYears / 0.2408467;
      }

      double on_venus() const {
          return earthYears / 0.61519726;
      }

      double on_mars() const {
          return earthYears / 1.8808158;
      }

      double on_jupiter() const {
          return earthYears / 11.862615;
      }

      double on_saturn() const {
          return earthYears / 29.447498;
      }

      double on_uranus() const {
          return earthYears / 84.016846;
      }

      double on_neptune() const {
          return earthYears / 164.79132;
      }

  };

}  // namespace space_age

#endif // SPACE_AGE_H