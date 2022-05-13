package com.cyberproject.sqlinjection.student;

import java.util.*;
import org.springframework.data.repository.CrudRepository;
import javax.persistence.*;
import java.util.stream.Collectors;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Transactional;

//entityManager.createNativeQuery("Select lastpr FROM StockPrice WHERE scrip=:scrip and prdate = :prdate")
//                    .setParameter("scrip", scrip)
//                    .setParameter("prdate", prdate)
//                    .getSingleResult();

public class StudentRepository{

    @Autowired
    private EntityManager entityManager;
	
	@Transactional
    public void save(Student student) {
        entityManager.persist(student);
    }
	
	
    public Collection<Student> findStudent(String firstName){
		String customQuery = " SELECT * FROM student WHERE first_name = '" + firstName + "' ";
		return  entityManager.createNativeQuery(customQuery, Student.class).getResultList();
	}

}
