package br.mackmusic.mackmusic.controller;

import br.mackmusic.mackmusic.model.User;

import java.util.UUID;

public record UserDTO(
        UUID id,
        String name,
        String email,
        String password
) {
    public static UserDTO fromEntity(User user) {
        return new UserDTO(
                user.getId(),
                user.getName(),
                user.getEmail(),
                null
        );
    }

    public User toEntity() {
        User user = new User();
        user.setId(this.id);
        user.setEmail(this.email);
        user.setName(this.name);
        user.setPassword(this.password);
        return user;
    }


}

