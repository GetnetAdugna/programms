package com.cyberproject.sqlinjection;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

import com.cyberproject.sqlinjection.student.Student;
import com.cyberproject.sqlinjection.student.StudentRepository;
import java.util.*;

@SpringBootApplication
public class SqlinjectionApplication {

	public static void main(String[] args) {
		SpringApplication.run(SqlinjectionApplication.class, args);
	}
	
	@Bean
	public CommandLineRunner dataLoader(StudentRepository repo) {
		return args -> {

			ArrayList<Student> students = new ArrayList<>(
				Arrays.asList(
					new Student("UGR/1/12", "Yared", "Hailu", 3, "Software", 3.4),
					new Student("UGR/2/12", "Samuel", "Asmare", 3, "Software", 3.5),
					new Student("UGR/3/12", "Bereket", "Kebede", 3, "Software", 3.0),
					new Student("UGR/4/12", "Biruk", "Hailu", 3, "Software", 3.1),
					new Student("UGR/5/12", "Mastewal", "Sisay", 3, "Software", 3.2),
					new Student("UGR/6/12", "Henok", "Hailu", 3, "Software", 3.9),
					new Student("UGR/7/12", "Selam", "Kelemu", 3, "Software", 3.55),
					new Student("UGR/8/12", "Kenubish", "Sewhulu", 3, "Software", 3.89),
					new Student("UGR/9/12", "Mariya", "Hailu", 3, "Software", 3.77),
					new Student("UGR/10/12", "Mic", "John", 3, "Software", 3.46)
				)
			);
			
			for (Student student : students){
				repo.save(student);
			}

		};
	}

}
