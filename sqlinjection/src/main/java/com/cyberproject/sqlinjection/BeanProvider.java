package com.cyberproject.sqlinjection;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import com.cyberproject.sqlinjection.student.StudentRepository;
import java.util.*;

@Configuration
public class BeanProvider {
	
	@Bean
	public StudentRepository getStudentRepo() {
		return new StudentRepository();
	}

}
