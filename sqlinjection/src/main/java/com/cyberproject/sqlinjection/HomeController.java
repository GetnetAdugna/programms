package com.cyberproject.sqlinjection;

import lombok.extern.slf4j.Slf4j;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.bind.annotation.SessionAttribute;
import com.cyberproject.sqlinjection.student.*;
import java.util.*;
import lombok.*;

@Data
class SearchForm {
	public String firstName;
	SearchForm(String firstName){
		this.firstName = firstName;
	}
}

@Controller
@Slf4j
public class HomeController {

    @Autowired
    StudentRepository studentRepository;

    @GetMapping("/")
    public String home(Model model) {
		model.addAttribute("form", new SearchForm(""));
		model.addAttribute("loaded", false);
        return "index";
    }
	
	
    @PostMapping("/")
    public String home(SearchForm form, Model model) {
		log.info("Processing with first name "+form.firstName);
		Collection<Student> students  = studentRepository.findStudent(form.firstName);
		log.info("Length "+students.size());
		model.addAttribute("loaded", true);
		model.addAttribute("form", new SearchForm(""));
        model.addAttribute("students", students);
        return "index";
    }
}
