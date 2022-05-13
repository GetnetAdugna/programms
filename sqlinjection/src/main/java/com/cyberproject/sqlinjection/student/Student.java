package com.cyberproject.sqlinjection.student;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import lombok.*;

import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;

@Entity
@Data
@NoArgsConstructor
@AllArgsConstructor
public class Student {
    @Id
    private String studentId;
    private String firstName;
    private String lastName;
    private int year;
    private String department;
    private double grade;
}
